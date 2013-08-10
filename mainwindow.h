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
#include <algorithm>
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
#include <QErrorMessage>
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

class MainWindow : public QMainWindow {
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
    cv::RNG rng;

    bool eventFilter (QObject* watched, QEvent* e);

    void ouvrirImage (const char* nomFichier);
    const QPixmap imageToQPixmap (const char* nomFichier);
    void creerFenetre (const QPixmap& pixmap, const QString& titre);

    QScrollArea* getFocusedArea ();
    QScrollArea* getFirstUnfocusedArea ();
    QLabel* getFocusedLabel ();
    QLabel* getFirstUnfocusedLabel ();
    QLabel* getLabelInArea (QScrollArea* scrollArea);

    void adjustScrollBar (QScrollBar* scrollBar, double facteur);
    void updateZoomActions (QLabel* image);

    void scaleImage (QScrollArea* scrollArea, double facteur);

    //menu outils
    void afficherHistogramme (QLabel* label);
    void calculerHistogramme (QImage& argbImage, QString titre);
    void afficherRecadrage (QLabel* label);
    void calculerRecadrage (QImage& argbImage, QString titre);
    void afficherHistogrammeNegatif (QLabel* label);
    void calculerHistogrammeNegatif (QImage& argbImage, QString titre);
    void afficherAddition (QLabel* labelGauche, QLabel* labelDroite);
    void calculerAddition (QImage& argbImageGauche, QImage& argbImageDroite, QString titre);
    void afficherSoustraction (QLabel* labelGauche, QLabel* labelDroite);
    void calculerSoustraction (QImage& argbImageGauche, QImage& argbImageDroite, QString titre);
    void afficherCombinaison (QLabel* labelGauche, QLabel* labelDroite);
    void calculerCombinaison (QImage& argbImageGauche, QImage& argbImageDroite, QString titre, double alpha);
    void afficherNOT (QLabel* label);
    void calculerNOT (QImage& argbImage, QString titre);
    void afficherPlanBinaire (QLabel* label);
    void calculerPlanBinaire (QImage& argbImage, QString titre, int bit);
    void afficherQuantification (QLabel* label);
    void calculerQuantification (QImage& argbImage, QString titre, int bits);
    void afficherBruitUniforme (QLabel* label);
    void calculerBruitUniforme (QImage& argbImage, QString titre, int valeur = 127);
    void afficherBruitPoivreEtSel (QLabel* label);
    void calculerBruitPoivreEtSel (QImage& argbImage, QString titre, double pourcentage);
    void afficherUniforme ();
    void afficherUniforme (QLabel* label);
    void calculerUniforme (QImage& argbImage, QString titre, int valeur = 0);
    void afficherRampe ();
    void afficherRampe (QLabel* label);
    void calculerRampe (QImage& argbImage, QString titre);
    void calculerRampe (QImage& argbImage, QString titre, int blue, int rouge, int vert);

    //menu filtrage
    void afficherMoyenneur3x3 (QLabel* label);
    void calculerMoyenneur3x3 (QImage& argbImage, QString titre, cv::Point anchor = cv::Point(-1, -1), int borderType = cv::BORDER_DEFAULT);
    void afficherMoyenneurNxN (QLabel* label);
    void calculerMoyenneurNxN (QImage& argbImage, QString titre, cv::Size ksize = cv::Size(3,3), cv::Point anchor = cv::Point(-1, -1), int borderType = cv::BORDER_DEFAULT);
    void afficherLaplacien (QLabel* label);
    void calculerLaplacien (QImage& argbImage, QString titre, int ksize = 3, double gain = 1, double offset = 0, int borderType = cv::BORDER_DEFAULT);
    void afficherMedian (QLabel* label);
    void calculerMedian (QImage& argbImage, QString titre, int ksize = 3);
    void afficherFFT (QLabel* label);
    void calculerFFT (QImage& argbImage, QString titre);

    //menu segmentation
    void afficherSeuillageManuelSimple (QLabel* label);
    void calculerSeuillageManuelSimple (QImage& argbImage, QString titre, double seuil, double maxval = 255);
    void afficherSeuillageManuelDouble (QLabel* label);
    void calculerSeuillageManuelDouble (QImage& argbImage, QString titre, double seuil, double maxval = 255);
    void afficherSeuillageParHysteresis (QLabel* label);
    void calculerSeuillageParHysteresis (QImage& argbImage, QString titre, int seuilBas, int seuilHaut, int ksize = 3, bool utiliserNormeL2 = false);
    void afficherGradientSobel (QLabel* label, TypeSobel type);
    void calculerGradientSobel (QImage& argbImage, QString titre, TypeSobel, int ksize = 3, double gain = 1, double offset = 0, int borderType = cv::BORDER_DEFAULT);

private slots:
    void on_actionOuvrir_triggered ();

    void on_actionTailleNormale_triggered ();
    void on_actionZoomIn_triggered ();
    void on_actionZoomOut_triggered ();

    //menu outils
    void on_actionAffichage_triggered ();
    void on_actionRecadrage_triggered ();
    void on_actionNegatif_triggered ();
    void on_actionAddition_triggered ();
    void on_actionSoustraction_triggered ();
    void on_actionCombinaison_triggered ();
    void on_actionNOT_triggered ();
    void on_actionPlanBinaire_triggered ();
    void on_actionQuantification_triggered ();
    void on_actionBruitUniforme_triggered ();
    void on_actionBruitPoivreEtSel_triggered ();
    void on_actionUniforme_triggered ();
    void on_actionRampe_triggered ();

    //menu filtrage
    void on_actionMoyenneur3x3_triggered ();
    void on_actionMoyenneurNxN_triggered ();
    void on_actionLaplacien_triggered ();
    void on_actionMedian_triggered ();
    void on_actionFFT_triggered ();

    //menu segmentation
    void on_actionManuelSimple_triggered ();
    void on_actionManuelDouble_triggered ();
    void on_actionSeuillageParHysteresis_triggered ();
    void on_actionNormeSobel_triggered ();
    void on_actionGradientXSobel_triggered ();
    void on_actionGradientYSobel_triggered ();
};

void QImageTocvMat (const QImage& in, cv::Mat& out);
void cvMatToQImage (const cv::Mat& in, QImage& out);

#endif // MAINWINDOW_H
