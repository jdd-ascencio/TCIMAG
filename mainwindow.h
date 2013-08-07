/*!
 * @file mainwindow.h
 * @author Juan ASCENCIO
 * @version 1.0
 * @date Juillet 2013
 * @copyright INSA LYON
 * Creation date 2013-07-04T17:30:28
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <typeinfo>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QtCore>
#include <QObject>
#include <QString>
#include <QHash>
#include <QApplication>
#include <QMouseEvent>
#include <QWidget>
#include <QMainWindow>
#include <QLayout>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QStatusBar>
#include <QToolBar>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QScrollArea>
#include <QScrollBar>
#include <QLabel>
#include <QInputDialog>
#include <QFileDialog>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QImage>
#include <QRgb>
#include <QRect>

namespace Ui {
class MainWindow;
}

  enum TypeSobel {SOBEL_NORME, SOBEL_X, SOBEL_Y};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    static const char* PATTERN_OUVERTURE_IMAGES_LEGACY;
    static const char* PATTERN_OUVERTURE_IMAGES_QT;
    static const char* PATTERN_OUVERTURE_IMAGES_OPENCV;
    static const char* PATTERN_OUVERTURE_IMAGES_QT_OU_OPENCV;
    static const char* PATTERN_OUVERTURE_IMAGES_QT_ET_OPENCV;
    static const char* DOSSIER_DEFAUT_OUVERTURE_IMAGES;
    static const uint BORDER_TYPE = cv::BORDER_DEFAULT;

    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    template<class T>
    QObject* findFirstChildClassOf(const QList<QObject*> &children);

private:
    Ui::MainWindow* ui;
    QHash<uint, double> scaleFactor;
    QHash<uint, QString> windowTitle;

    bool eventFilter (QObject* watched, QEvent* e);

    //const cv::Mat qtRGBToCvBGR (const QImage& argbImage, enum QImage::Format format);
    //const QImage cvBGRToQtRGB (const cv::Mat& bgrImage, enum QImage::Format format);
    const QPixmap imageToQPixmap (const char* nomFichier);
    void creerFenetre (const QPixmap& pixmap, const QString& titre);
    QScrollArea* getFocusedArea ();
    QScrollArea* getFirstUnfocusedArea();
    QLabel* getFocusedLabel();
    QLabel* getFirstUnfocusedLabel();
    QLabel* getLabelInArea (QScrollArea* scrollArea);

    void ouvrirImage (const char* nomFichier);

    void scaleImage (double factor, QScrollArea* paneau);
    void adjustScrollBar (double factor, QScrollBar* scrollBar);
    void updateZoomActions (QLabel* image);

    //menu outils
    void afficherHistogramme (QLabel* label);
    void calculerHistogramme (QImage& argbImage, QString titre);
    void afficherHistogrammeNegatif (QLabel* label);
    void calculerHistogrammeNegatif (QImage& argbImage, QString titre);
    void afficherAddition (QLabel* label1, QLabel* label2);
    void calculerAddition (QImage& argbImageGauche, QImage& argbImageDroite, QString titre);
    void afficherSoustraction (QLabel* label1, QLabel* label2);
    void calculerSoustraction (QImage& argbImageGauche, QImage& argbImageDroite, QString titre);

    //menu filtrage
    void afficherLaplacien (QLabel* label);
    void calculerLaplacien (QImage& argbImage, QString titre, int ksize = 3, double gain = 1, double offset = 0, uint borderType = cv::BORDER_DEFAULT);

    //menu segmentation
    void afficherSeuillageManuelSimple (QLabel* label);
    void calculerSeuillageManuelSimple (QImage& argbImage, QString titre, double seuil, double maxval = 255);
    void afficherSeuillageManuelDouble (QLabel* label);
    void calculerSeuillageManuelDouble (QImage& argbImage, QString titre, double seuil, double maxval = 255);
    void afficherSeuillageParHysteresis (QLabel* label);
    void calculerSeuillageParHysteresis (QImage& argbImage, QString titre, int seuilBas, int seuilHaut, int ksize = 3, bool utiliserNormeL2 = false);
    void afficherGradientSobel (QLabel* label, TypeSobel type);
    void calculerGradientSobel (QImage& argbImage, QString titre, TypeSobel, int ksize = 3, double gain = 1, double offset = 0, uint borderType = cv::BORDER_DEFAULT);

private slots:
    void on_actionOuvrir_triggered ();

    void on_actionTailleNormale_triggered ();
    void on_actionZoomIn_triggered ();
    void on_actionZoomOut_triggered ();

    //menu outils
    void on_actionAffichage_triggered ();
    void on_actionNegatif_triggered ();
    void on_actionAddition_triggered ();
    void on_actionSoustraction_triggered ();

    //menu filtrage
    void on_actionLaplacien_triggered ();

    //menu segmentation
    void on_actionManuelSimple_triggered ();
    void on_actionManuelDouble_triggered ();
    void on_actionSeuillageParHysteresis_triggered ();
    void on_actionGradientXSobel_triggered ();
    void on_actionGradientYSobel_triggered ();
};

void QImageTocvMat(const QImage& in, cv::Mat& out);
void cvMatToQImage(const cv::Mat& in, QImage& out);

#endif // MAINWINDOW_H
