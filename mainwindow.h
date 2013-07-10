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

    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    template<class T>
    QObject* findFirstChildClassOf(const QList<QObject*> &children);

private:
    Ui::MainWindow* ui;
    QHash<uint, double> scaleFactor;

    bool eventFilter (QObject* watched, QEvent* e);

    const QPixmap imageToQPixmap (const char* nomFichier, enum QImage::Format format);
    QImage cvBGRToQtRGB (const cv::Mat& bgrImage, enum QImage::Format format);
    cv::Mat qtRGBToCvBGR (const QImage& rgbImage, enum QImage::Format format);
    void ouvrirImage (const char* nomFichier);
    void creerFenetre (const QPixmap& pixmap, const QString &titre);
    void scaleImage (double factor, QScrollArea* paneau);
    void adjustScrollBar (double factor, QScrollBar* scrollBar);
    void updateZoomActions (QLabel* image);
    QScrollArea* getFocusedArea ();

private slots:
    void on_actionOuvrir_triggered ();
    void on_actionTailleNormale_triggered ();
    void on_actionZoomIn_triggered ();
    void on_actionZoomOut_triggered ();
};

#endif // MAINWINDOW_H
