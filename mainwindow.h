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
  enum TypePrewitt {PREWITT_NORME, PREWITT_X, PREWITT_Y};
  enum CodePalette {CVT_COLOR_INVERSE, THERMAL, CVT_COLOR, MRI, COLD_TO_HOT, JET};

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    static const char* PATTERN_OUVERTURE_IMAGES_LEGACY;
    static const char* PATTERN_OUVERTURE_IMAGES_QT;
    static const char* PATTERN_OUVERTURE_IMAGES_OPENCV;
    static const char* PATTERN_OUVERTURE_IMAGES_QT_OU_OPENCV;
    static const char* PATTERN_OUVERTURE_IMAGES_QT_ET_OPENCV;
    static const char* DOSSIER_DEFAUT_OUVERTURE_IMAGES;
    static const int BORDER_TYPE = cv::BORDER_DEFAULT;
    static const int SEUILLAGE_VALEUR_MIL = 127;
    static const int SEUILLAGE_VALEUR_MAX = 255;

    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    QHash<uint, double> scaleFactor;
    QHash<uint, QString> windowTitle;
    cv::RNG rng;

    bool eventFilter (QObject* watched, QEvent* e);

    QScrollArea* getFocusedArea ();
    QScrollArea* getFirstUnfocusedArea ();
    QLabel* getFocusedLabel ();
    QLabel* getFirstUnfocusedLabel ();
    QLabel* getLabelInArea (QScrollArea* scrollArea);
    template<class T>
    T* findFirstChildClassOf(const QList<QObject*> &children);


    //menu fichier
    void ouvrirImage (const char* nomFichier);
    void creerFenetre (const QPixmap& pixmap, const QString& titre);
    const QPixmap imageToQPixmap (const char* nomFichier);
    void fermerTout();
    void detruire(QScrollArea* scrollArea);

    //menu affichage
    void scaleImage (QScrollArea* scrollArea, double facteur);
    void adjustScrollBar (QScrollBar* scrollBar, double facteur);
    void updateZoomActions (QLabel* image);
    void afficherPalette (QLabel* label, CodePalette code);
    void calculerPalette (QImage& argbImage, QString titre, CodePalette code);
    void dupliquer (QLabel* label);

    //menu outils
    void afficherHistogramme (QLabel* label);
    void calculerHistogramme (QImage& argbImage, QString titre);
    void afficherRecadrage (QLabel* label);
    void calculerRecadrage (QImage& argbImage, QString titre);
    void afficherHistogrammeNegatif (QLabel* label);
    void calculerHistogrammeNegatif (QImage& argbImage, QString titre);
    void afficherCalibration (QLabel* label);
    void calculerCalibration (QImage& argbImage, QString titre, double valeurMin, double valeurMax);
    void afficherEgalisation (QLabel* label);
    void calculerEgalisation (QImage& argbImage, QString titre);
    void afficherExponentielle (QLabel* label);
    void calculerExponentielle (QImage& argbImage, QString titre);
    void afficherLogarithmique (QLabel* label);
    void calculerLogarithmique (QImage& argbImage, QString titre);
    void afficherAddition (QLabel* labelGauche, QLabel* labelDroite);
    void calculerAddition (QImage& argbImageGauche, QImage& argbImageDroite, QString titre);
    void afficherSoustraction (QLabel* labelGauche, QLabel* labelDroite);
    void calculerSoustraction (QImage& argbImageGauche, QImage& argbImageDroite, QString titre);
    void afficherCombinaison (QLabel* labelGauche, QLabel* labelDroite);
    void calculerCombinaison (QImage& argbImageGauche, QImage& argbImageDroite, QString titre, double alpha);
    void afficherMinimum (QLabel* labelGauche, QLabel* labelDroite);
    void calculerMinimum (QImage& argbImageGauche, QImage& argbImageDroite, QString titre);
    void afficherMaximum (QLabel* labelGauche, QLabel* labelDroite);
    void calculerMaximum (QImage& argbImageGauche, QImage& argbImageDroite, QString titre);
    void afficherAND (QLabel* labelGauche, QLabel* labelDroite);
    void calculerAND (QImage& argbImageGauche, QImage& argbImageDroite, QString titre);
    void afficherOR (QLabel* labelGauche, QLabel* labelDroite);
    void calculerOR (QImage& argbImageGauche, QImage& argbImageDroite, QString titre);
    void afficherXOR (QLabel* labelGauche, QLabel* labelDroite);
    void calculerXOR (QImage& argbImageGauche, QImage& argbImageDroite, QString titre);
    void afficherNOT (QLabel* label);
    void calculerNOT (QImage& argbImage, QString titre);
    void afficherPlanBinaire (QLabel* label);
    void calculerPlanBinaire (QImage& argbImage, QString titre, int bit);
    void afficherQuantification (QLabel* label);
    void calculerQuantification (QImage& argbImage, QString titre, int bits);
    void afficherChangementDEchelle (QLabel* label);
    void calculerChangementDEchelle (QImage& argbImage, QString titre, int dimX, int dimY);
    void afficherRotation (QLabel* label);
    void calculerRotation (QImage& argbImage, QString titre, double angle, double zoom);
    void afficherRotationInterpolee (QLabel* label);
    void calculerRotationInterpolee (QImage& argbImage, QString titre, double angle, double zoom);
    void afficherTransposee (QLabel* label);
    void calculerTransposee (QImage& argbImage, QString titre);
    void afficherVuePerspective (QLabel* label);
    void calculerVuePerspective (QImage& argbImage, QString titre);
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
    void afficherVFiltre (QLabel* label);
    void calculerVFiltre (QImage& argbImage, QString titre, int ksize = 3);
    void afficherFFT (QLabel* label);
    void calculerFFT (QImage& argbImage, QString titre);

    //menu segmentation
    void afficherSeuillageManuelSimple (QLabel* label);
    void calculerSeuillageManuelSimple (QImage& argbImage, QString titre, double seuil, double maxval = SEUILLAGE_VALEUR_MAX);
    void afficherSeuillageVarianceSimple (QLabel* label);
    void calculerSeuillageVarianceSimple (QImage& argbImage, QString titre, double seuil, double maxval = SEUILLAGE_VALEUR_MAX);
    void afficherSeuillageManuelDouble (QLabel* label);
    void calculerSeuillageManuelDouble (QImage& argbImage, double seuilBas, double seuilHaut, double minVal = 0, double midVal = SEUILLAGE_VALEUR_MIL, double maxVal = SEUILLAGE_VALEUR_MAX);
    void afficherSeuillageVarianceDouble (QLabel* label);
    void calculerSeuillageVarianceDouble (QImage& argbImage, QString titre, double seuilBas, double seuilHaut, double minVal = 0, double midVal = SEUILLAGE_VALEUR_MIL, double maxVal = SEUILLAGE_VALEUR_MAX);
    void afficherSeuillageParHysteresis (QLabel* label);
    void calculerSeuillageParHysteresis (QImage& argbImage, QString titre, int seuilBas, int seuilHaut);
    void traiterPixelHysteresisfw (cv::Mat& bgrMat, cv::Mat& validation, int x, int y, int cols, int rows);
    void traiterPixelHysteresisbw (cv::Mat& bgrMat, cv::Mat& validation, int x, int y, int cols, int rows);
    void afficherBiseuillage (QLabel* label);
    void calculerBiseuillage (QImage& argbImage, QString titre, int seuilBas, int seuilHaut);
    void traiterPixelBiseuillage (cv::Mat& bgrMat, cv::Mat& validation, int x, int y, int cols, int rows);
    void afficherGradientSobel (QLabel* label, TypeSobel type);
    void calculerGradientSobel (QImage& argbImage, QString titre, TypeSobel, int ksize = 3, double gain = 1, double offset = 0, int borderType = cv::BORDER_DEFAULT);
    void afficherGradientPrewitt (QLabel* label, TypePrewitt type);
    void calculerGradientPrewitt (QImage& argbImage, QString titre, TypePrewitt type, double gain = 1, double offset = 0, int borderType = cv::BORDER_DEFAULT);

private slots:
    //menu fichier
    void on_actionOuvrir_triggered ();
    void on_actionFermerTout_triggered ();

    //menu affichage
    void on_actionTailleNormale_triggered ();
    void on_actionZoomIn_triggered ();
    void on_actionZoomOut_triggered ();
    void on_actionCvtColorInverse_triggered ();
    void on_actionThermal_triggered ();
    void on_actionCvtColor_triggered ();
    void on_actionMRI_triggered ();
    void on_actionColdToHot_triggered ();
    void on_actionJet_triggered ();
    void on_actionDupliquer_triggered ();

    //menu outils
    void on_actionAffichage_triggered ();
    void on_actionRecadrage_triggered ();
    void on_actionNegatif_triggered ();
    void on_actionCalibration_triggered ();
    void on_actionEgalisation_triggered ();
    void on_actionLogarithmique_triggered ();
    void on_actionExponentielle_triggered ();
    void on_actionAddition_triggered ();
    void on_actionSoustraction_triggered ();
    void on_actionCombinaison_triggered ();
    void on_actionMinimum_triggered ();
    void on_actionMaximum_triggered ();
    void on_actionAND_triggered ();
    void on_actionOR_triggered ();
    void on_actionXOR_triggered ();
    void on_actionNOT_triggered ();
    void on_actionPlanBinaire_triggered ();
    void on_actionQuantification_triggered ();
    void on_actionChangementDEchelle_triggered ();
    void on_actionRotation_triggered ();
    void on_actionRotationInterpolee_triggered ();
    void on_actionTransposee_triggered ();
    void on_actionVuePerspective_triggered ();
    void on_actionBruitUniforme_triggered ();
    void on_actionBruitPoivreEtSel_triggered ();
    void on_actionUniforme_triggered ();
    void on_actionRampe_triggered ();

    //menu filtrage
    void on_actionMoyenneur3x3_triggered ();
    void on_actionMoyenneurNxN_triggered ();
    void on_actionLaplacien_triggered ();
    void on_actionMedian_triggered ();
    void on_actionVFiltre_triggered ();
    void on_actionFFT_triggered ();

    //menu segmentation
    void on_actionManuelSimple_triggered ();
    void on_actionVarianceSimple_triggered ();
    void on_actionManuelDouble_triggered ();
    void on_actionVarianceDouble_triggered ();
    void on_actionSeuillageParHysteresis_triggered ();
    void on_actionBiseuillage_triggered ();
    void on_actionNormeSobel_triggered ();
    void on_actionGradientXSobel_triggered ();
    void on_actionGradientYSobel_triggered ();
    void on_actionNormePrewitt_triggered ();
    void on_actionGradientXPrewitt_triggered ();
    void on_actionGradientYPrewitt_triggered ();
};

double interpolatationLineaire (double val, double y0, double x0, double y1, double x1);
void Prewitt(cv::InputArray _src, cv::OutputArray _dst, int ddepth, int dx, int dy, double gain = 1, double offset = 0, int borderType = cv::BORDER_DEFAULT);
void QImageTocvMat (const QImage& in, cv::Mat& out);
void cvMatToQImage (const cv::Mat& in, QImage& out);

#endif // MAINWINDOW_H
