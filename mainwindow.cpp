/*!
 * @file mainwindow.cpp
 * @author Juan ASCENCIO
 * @version 1.0
 * @date Juillet 2013
 * @copyright INSA LYON
 * Creation date 2013-07-04T17:30:28
 */



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "intintdialog.h"
#include "doubledoubledialog.h"
#include "doubleintdialog.h"



const char* MainWindow::PATTERN_OUVERTURE_IMAGES_LEGACY = "Images ACR/NEMA (*.acr);;"
                                                   "Images Windows Bitmap (*.bmp);;"
                                                   "Images Personal Computer eXchange(*.pcx);;"
                                                   "Images Visilog (*.vsl);;"
                                                   "Toutes les Images (*.acr *.bmp *.pcx *.vsl);;"
                                                   "Tout Type (*.*)";
const char* MainWindow::PATTERN_OUVERTURE_IMAGES_QT = "Images Windows Bitmap (*.bmp);;"
                                               "Images Graphics Interchange Format (*.gif);;"
                                               "Images Joint Photographic Experts Group (*.jpg *jpeg);;"
                                               "Images Portable Network Graphics (*.png);;"
                                               "Images Portable Bitmap (*.pbm);;"
                                               "Images Portable Graymap (*.pgm);;"
                                               "Images Portable Pixmap (*.ppm);;"
                                               "Images Tagged Image File Format (*.tif *.tiff);;"
                                               "Images X11 Bitmap (*.xbm);;"
                                               "Images X11 Pixmap (*.xpm);;"
                                               "Toutes les Images (*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm *.tif *.tiff *.xbm *xpm);;"
                                               "Tout Type (*.*)";
const char* MainWindow::PATTERN_OUVERTURE_IMAGES_OPENCV = "Images Windows Bitmap (*.bmp *.dib);;"
                                                   "Images Joint Photographic Experts Group (*.jpg *jpeg *jpe);;"
                                                   "Images Joint Photographic Experts Group 2000 (*jp2);;"
                                                   "Images Portable Network Graphics (*.png);;"
                                                   "Images Portable Bitmap (*.pbm);;"
                                                   "Images Portable Graymap (*.pgm);;"
                                                   "Images Portable Pixmap (*.ppm);;"
                                                   "Images Sun Raster (*.ras *.sr);;"
                                                   "Images Tagged Image File Format (*.tif *.tiff);;"
                                                   "Toutes les Images (*.bmp *.dib *.jpg *.jpeg *jpe *jp2 *.png *.pbm *.pgm *.ppm *.ras *.sr *.tif *.tiff);;"
                                                   "Tout Type (*.*)";
const char* MainWindow::PATTERN_OUVERTURE_IMAGES_QT_OU_OPENCV = "Images Windows Bitmap (*.bmp *.dib);;"
                                                         "Images Graphics Interchange Format (*.gif);;"
                                                         "Images Joint Photographic Experts Group (*.jpg *jpeg *.jpe);;"
                                                         "Images Joint Photographic Experts Group 2000 (*jp2);;"
                                                         "Images Portable Network Graphics (*.png);;"
                                                         "Images Portable Bitmap (*.pbm);;"
                                                         "Images Portable Graymap (*.pgm);;"
                                                         "Images Portable Pixmap (*.ppm);;"
                                                         "Images Sun Raster (*.ras *.sr);;"
                                                         "Images Tagged Image File Format (*.tif *.tiff);;"
                                                         "Images X11 Bitmap (*.xbm);;"
                                                         "Images X11 Pixmap (*.xpm);;"
                                                         "Toutes les Images (*.bmp *.dib *.gif *.jpg *.jpeg *.jpe *.jp2 *.png *.pbm *.pgm *.ppm *.ras *.sr *.tif *.tiff *.xbm *xpm);;"
                                                         "Tout Type (*.*)";
const char* MainWindow::PATTERN_OUVERTURE_IMAGES_QT_ET_OPENCV = "Images Windows Bitmap (*.bmp);;"
                                                         "Images Joint Photographic Experts Group (*.jpg *jpeg);;"
                                                         "Images Portable Network Graphics (*.png);;"
                                                         "Images Portable Bitmap (*.pbm);;"
                                                         "Images Portable Graymap (*.pgm);;"
                                                         "Images Portable Pixmap (*.ppm);;"
                                                         "Images Tagged Image File Format (*.tif *.tiff);;"
                                                         "Toutes les Images (*.bmp *.jpg *.jpeg *.png *.pbm *.pgm *.ppm *.tif *.tiff);;"
                                                         "Tout Type (*.*)";
const char* MainWindow::DOSSIER_DEFAUT_OUVERTURE_IMAGES = "./../TCIMAG_ressources";



MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent), ui (new Ui::MainWindow) {
    ui->setupUi(this);
    rng = cv::RNG(cv::getTickCount());
    dernierTempsDeCalcul = 0;

    ///DEBUG
    //ouvrirImage("../TCIMAG_ressources/lena.bmp");
    //ouvrirImage("../TCIMAG_ressources/lenaGray.bmp");
    //ouvrirImage("../TCIMAG_ressources/lena.jpg");
    //ouvrirImage("../TCIMAG_ressources/lena.jpeg");
    //ouvrirImage("../TCIMAG_ressources/lena.png");
    //ouvrirImage("../TCIMAG_ressources/lena.pgm");
    //ouvrirImage("../TCIMAG_ressources/lena.ppm");
    //ouvrirImage("../TCIMAG_ressources/lena.tiff");

    ///PARTIE_1
    //ouvrirImage("../TCIMAG_ressources/AQUITAIN.PNG");
    //ouvrirImage("../TCIMAG_ressources/BUREAU.PNG");
    //ouvrirImage("../TCIMAG_ressources/CLEF.PNG");
    //ouvrirImage("../TCIMAG_ressources/MEB.PNG");
    //ouvrirImage("../TCIMAG_ressources/MUSCLE.PNG");
    //ouvrirImage("../TCIMAG_ressources/REGLE.PNG");
    //ouvrirImage("../TCIMAG_ressources/RONDELLE.PNG");
    //ouvrirImage("../TCIMAG_ressources/SCANNER.PNG");
    //ouvrirImage("../TCIMAG_ressources/SIC.PNG");
    //ouvrirImage("../TCIMAG_ressources/SPOT.PNG");

    ///PARTIE_2
    //ouvrirImage("../TCIMAG_ressources/ANGIO.PNG");
    //ouvrirImage("../TCIMAG_ressources/BOUGIES.PNG");
    //ouvrirImage("../TCIMAG_ressources/LENA.PNG");
    //ouvrirImage("../TCIMAG_ressources/MUSCLE.PNG");
    //ouvrirImage("../TCIMAG_ressources/QUITO.PNG");
    //ouvrirImage("../TCIMAG_ressources/RONDELLE.PNG");

    ///PARTIE_3
    //ouvrirImage("../TCIMAG_ressources/AMOUR.PNG");
    //ouvrirImage("../TCIMAG_ressources/BRUIT.PNG");
    //ouvrirImage("../TCIMAG_ressources/FILM.PNG");
    //ouvrirImage("../TCIMAG_ressources/FISSURE.PNG");
    //ouvrirImage("../TCIMAG_ressources/MEB.PNG");
    //ouvrirImage("../TCIMAG_ressources/MORPHO.PNG");
    //ouvrirImage("../TCIMAG_ressources/OBJETS.PNG");
    //ouvrirImage("../TCIMAG_ressources/RONDELLE.PNG");
    //ouvrirImage("../TCIMAG_ressources/SPOT.PNG");
}

MainWindow::~MainWindow () {
    delete ui;
}

///
///
///   fonctions
///
///

double interpolatationLineaire (double val, double y0, double x0, double y1, double x1) {
    return (val-x0)*(y1-y0)/(x1-x0) + y0;
}

void Prewitt(cv::InputArray _src, cv::OutputArray _dst, int ddepth, int dx, int dy, double gain, double offset, int borderType) {
    cv::Mat src = _src.getMat();
    if (ddepth < 0)
        ddepth = src.depth();
    _dst.create(src.size(), CV_MAKETYPE(ddepth, src.channels()));
    cv::Mat dst = _dst.getMat();
    int ktype = std::max(CV_32F, std::max(ddepth, src.depth()));
    cv::Mat kx, ky;
    const int ksize = 3;
    CV_Assert(ktype == CV_32F || ktype == CV_64F);
    ((cv::OutputArray)kx).create(ksize, 1, ktype, -1, true);
    ((cv::OutputArray)ky).create(ksize, 1, ktype, -1, true);
    cv::Mat _kx = ((cv::OutputArray)kx).getMat();
    cv::Mat _ky = ((cv::OutputArray)ky).getMat();
    CV_Assert(dx >= 0 && dy >= 0 && dx+dy == 1);
    for(int k = 0; k < 2; k++) {
        cv::Mat* kernel = k == 0 ? &_kx : &_ky;
        int order = k == 0 ? dx : dy;
        int kerI[3];
        if( order == 0 )
            kerI[0] = 1, kerI[1] = 1, kerI[2] = 1;
        else if( order == 1 )
            kerI[0] = -1, kerI[1] = 0, kerI[2] = 1;
        cv::Mat temp(kernel->rows, kernel->cols, CV_32S, &kerI[0]);
        double scale = order == 1 ? 1. : 1./32;
        temp.convertTo(*kernel, ktype, scale);
    }
    if (gain != 1) {
        // usually the smoothing part is the slowest to compute, so try to scale it instead of the faster differenciating part
        if(dx == 0)
            kx *= gain;
        else
            ky *= gain;
    }
    cv::sepFilter2D(src, dst, ddepth, kx, ky, cv::Point(-1,-1), offset, borderType);
}

void QImageTocvMat(const QImage& in, cv::Mat& out) {
    QImage img = in.convertToFormat(QImage::Format_RGB888, Qt::ColorOnly);
    ////cv::Mat (int _rows, int _cols, int _type, void* _data, size_t _step=AUTO_STEP);
    cv::Mat matRGB(img.height(), img.width(), CV_8UC3, img.bits(), img.bytesPerLine());
    cv::cvtColor(matRGB, out, CV_RGB2BGR);
}

void cvMatToQImage(const cv::Mat& in, QImage& out) {
    cv::Mat matRGB(in);
    cv::cvtColor(in, matRGB, CV_BGR2RGB);
    ////QImage::QImage ( const uchar * data, int width, int height, int bytesPerLine, Format format )
    out = QImage((uchar*)matRGB.data, matRGB.cols, matRGB.rows, matRGB.step, QImage::Format_RGB888);
}

bool MainWindow::eventFilter (QObject* watched, QEvent* e) {
    if (e->type() == QEvent::MouseMove) {
        //// QLabel
        QWidget* src = (QWidget*) watched;
        QMouseEvent* event = (QMouseEvent*) e;
        int x = event->x(), y = event->y();
        if (x < 0 || x > src->width() || y < 0 || y > src->height())
            return QWidget::eventFilter(watched, e);
        //DEPRECATED
        //QPixmap pixmap = QPixmap::grabWidget(src, x, y, 1, 1);
        QPixmap pixmap = src->grab (QRect (x, y, 1, 1));
        QRgb rgb = pixmap.toImage().pixel(0,0);
        QString message = QString ("[X,Y]=[Alpha,Red,Green,Blue]Gray   |   [%1,%2]=[%3,%4,%5,%6]%7")
                .arg (QString::number (x), 3).arg (QString::number (y), 3)
                .arg (QString::number (qAlpha (rgb)), 3)
                .arg (QString::number (qRed (rgb)), 3).arg (QString::number (qGreen (rgb)), 3).arg (QString::number (qBlue (rgb)), 3)
                .arg (QString::number (qGray (rgb)));
        if (tempsCalcul.contains(qHash(watched)))
            message.append(QString("   \ttemps de calcul:%1 ms").arg(tempsCalcul[qHash(watched)]));
        statusBar()->showMessage(message);
    } else if (e->type() == QEvent::FocusIn) {
        //// QScrollableArea
        activerActionsUnaires();
        if(getFirstUnfocusedArea() != NULL) activerActionsBinaires();
        updateZoomActions (getLabelInArea ((QScrollArea*) watched));
    } else if (e->type() == QEvent::Close) {
        if (typeid(*watched) == typeid(QScrollArea)) {
            detruire((QScrollArea*) watched);
            desactiverActionsBinaires();
            desactiverActionsUnaires();
        }
    }
    return QWidget::eventFilter(watched, e);
}

QScrollArea* MainWindow::getFocusedArea() {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QList<QObject*> children = ui->centralWidget->children();
    if (children.isEmpty())
        return NULL;
    QObject* child = findFirstChildOfType<QWidget>(children);
    if (child == NULL)
        return NULL;
    children = child->children();
    if (children.isEmpty())
        return NULL;
    QScrollArea* scrollArea;
    for (int i = 0; i < children.size(); i++) {
        scrollArea = findFirstChildOfType<QScrollArea>(children.at(i)->children());
        if (scrollArea == NULL)
            continue;
        if (scrollArea->hasFocus())
            return scrollArea;
    }
    return NULL;
}

QScrollArea* MainWindow::getFirstUnfocusedArea() {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QList<QObject*> children = ui->centralWidget->children();
    if (children.isEmpty())
        return NULL;
    QObject* child = findFirstChildOfType<QWidget>(children);
    if (child == NULL)
        return NULL;
    children = child->children();
    if (children.isEmpty())
        return NULL;
    QScrollArea* scrollArea;
    for (int i = 0; i < children.size(); i++) {
        scrollArea = findFirstChildOfType<QScrollArea>(children.at(i)->children());
        if (scrollArea == NULL)
            continue;
        if (!scrollArea->hasFocus() && scrollArea->isActiveWindow())
            return scrollArea;
    }
    return NULL;
}

QLabel* MainWindow::getFocusedLabel() {
    ////
    ////QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QScrollArea* scrollArea = getFocusedArea();
    QLabel* focusedLabel = NULL;
    if (scrollArea == NULL)
        return NULL;
    QList<QObject*> children = scrollArea->children();
    if (children.isEmpty())
        return NULL;
    QObject* child = children.first();
    if (child == NULL)
        return NULL;
    children = child->children();
    if (children.isEmpty())
        return NULL;
    focusedLabel = (QLabel*) children.first();
    return focusedLabel;
}

QLabel* MainWindow::getFirstUnfocusedLabel() {
    ////
    ////QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QScrollArea* scrollArea = getFirstUnfocusedArea();
    QLabel* firstUnfocusedLabel = NULL;
    if (scrollArea == NULL)
        return NULL;
    QList<QObject*> children = scrollArea->children();
    if (children.isEmpty())
        return NULL;
    QObject* child = children.first();
    if (child == NULL)
        return NULL;
    children = child->children();
    if (children.isEmpty())
        return NULL;
    firstUnfocusedLabel = (QLabel*) children.first();
    return firstUnfocusedLabel;
}

QLabel* MainWindow::getLabelInArea (QScrollArea* scrollArea) {
    ////
    ////QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QLabel* label = NULL;
    if (scrollArea == NULL)
        return NULL;
    QList<QObject*> children = scrollArea->children();
    if (children.isEmpty())
        return NULL;
    QObject* child = children.first();
    if (child == NULL)
        return NULL;
    children = child->children();
    if (children.isEmpty())
        return NULL;
    label = (QLabel*) children.first();
    return label;
}

template<class T>
T* MainWindow::findFirstChildOfType(const QList<QObject*> &children) {
    T* child = NULL;
    for (int i = 0; i < children.size(); i++) {
        if (typeid(*children.at(i)) == typeid(T)) {
            child = (T*) children.at(i);
            break;
        } else
            child = NULL;
    }
    return child;
}

void MainWindow::activerActionsUnaires() {
    //menu fichier
    ui->actionFermerTout->setEnabled(true);

    //menu affichage
    ui->actionTailleNormale->setEnabled(true);
    ui->actionZoomIn->setEnabled(true);
    ui->actionZoomOut->setEnabled(true);
    ui->actionCvtColorInverse->setEnabled(true);
    ui->actionThermal->setEnabled(true);
    ui->actionCvtColor->setEnabled(true);
    ui->actionMRI->setEnabled(true);
    ui->actionColdToHot->setEnabled(true);
    ui->actionJet->setEnabled(true);
    ui->actionDupliquer->setEnabled(true);

    //menu outils
    ui->actionAffichage->setEnabled(true);
    ui->actionRecadrage->setEnabled(true);
    ui->actionNegatif->setEnabled(true);
    ui->actionCalibration->setEnabled(true);
    ui->actionEgalisation->setEnabled(true);
    ui->actionExponentielle->setEnabled(true);
    ui->actionLogarithmique->setEnabled(true);
    ui->actionPlanBinaire->setEnabled(true);
    ui->actionQuantification->setEnabled(true);
    ui->actionChangementDEchelle->setEnabled(true);
    ui->actionRotation->setEnabled(true);
    ui->actionRotationInterpolee->setEnabled(true);
    ui->actionTransposee->setEnabled(true);
    ui->actionVuePerspective->setEnabled(true);
    ui->actionBruitUniforme->setEnabled(true);
    ui->actionBruitPoivreEtSel->setEnabled(true);
    ui->actionUniforme->setEnabled(true);
    ui->actionRampe->setEnabled(true);

    //menu filtrage
    ui->actionMoyenneur3x3->setEnabled(true);
    ui->actionMoyenneurNxN->setEnabled(true);
    ui->actionLaplacien->setEnabled(true);
    ui->actionMedian->setEnabled(true);
    ui->actionVFiltre->setEnabled(true);
    ui->actionFFT->setEnabled(true);

    //menu segmentation
    ui->actionManuelSimple->setEnabled(true);
    ui->actionVarianceSimple->setEnabled(true);
    ui->actionManuelDouble->setEnabled(true);
    //ui->actionVarianceDouble->setEnabled(true);
    ui->actionSeuillageParHysteresis->setEnabled(true);
    ui->actionBiseuillage->setEnabled(true);
    ui->actionNormeSobel->setEnabled(true);
    ui->actionGradientXSobel->setEnabled(true);
    ui->actionGradientYSobel->setEnabled(true);
    ui->actionNormePrewitt->setEnabled(true);
    ui->actionGradientXPrewitt->setEnabled(true);
    ui->actionGradientYPrewitt->setEnabled(true);
}

void MainWindow::desactiverActionsUnaires() {
    //menu fichier
    ui->actionFermerTout->setEnabled(false);

    //menu affichage
    ui->actionTailleNormale->setEnabled(false);
    ui->actionZoomIn->setEnabled(false);
    ui->actionZoomOut->setEnabled(false);
    ui->actionCvtColorInverse->setEnabled(false);
    ui->actionThermal->setEnabled(false);
    ui->actionCvtColor->setEnabled(false);
    ui->actionMRI->setEnabled(false);
    ui->actionColdToHot->setEnabled(false);
    ui->actionJet->setEnabled(false);
    ui->actionDupliquer->setEnabled(false);

    //menu outils
    ui->actionAffichage->setEnabled(false);
    ui->actionRecadrage->setEnabled(false);
    ui->actionNegatif->setEnabled(false);
    ui->actionCalibration->setEnabled(false);
    ui->actionEgalisation->setEnabled(false);
    ui->actionExponentielle->setEnabled(false);
    ui->actionLogarithmique->setEnabled(false);
    ui->actionPlanBinaire->setEnabled(false);
    ui->actionQuantification->setEnabled(false);
    ui->actionChangementDEchelle->setEnabled(false);
    ui->actionRotation->setEnabled(false);
    ui->actionRotationInterpolee->setEnabled(false);
    ui->actionTransposee->setEnabled(false);
    //ui->actionVuePerspective->setEnabled(false);
    ui->actionBruitUniforme->setEnabled(false);
    ui->actionBruitPoivreEtSel->setEnabled(false);
    ui->actionUniforme->setEnabled(false);
    ui->actionRampe->setEnabled(false);

    //menu filtrage
    ui->actionMoyenneur3x3->setEnabled(false);
    ui->actionMoyenneurNxN->setEnabled(false);
    ui->actionLaplacien->setEnabled(false);
    ui->actionMedian->setEnabled(false);
    ui->actionVFiltre->setEnabled(false);
    ui->actionFFT->setEnabled(false);

    //menu segmentation
    ui->actionManuelSimple->setEnabled(false);
    ui->actionVarianceSimple->setEnabled(false);
    ui->actionManuelDouble->setEnabled(false);
    ui->actionVarianceDouble->setEnabled(false);
    ui->actionSeuillageParHysteresis->setEnabled(false);
    ui->actionBiseuillage->setEnabled(false);
    ui->actionNormeSobel->setEnabled(false);
    ui->actionGradientXSobel->setEnabled(false);
    ui->actionGradientYSobel->setEnabled(false);
    ui->actionNormePrewitt->setEnabled(false);
    ui->actionGradientXPrewitt->setEnabled(false);
    ui->actionGradientYPrewitt->setEnabled(false);
}

void MainWindow::activerActionsBinaires() {
    //menu outils
    ui->actionAddition->setEnabled(true);
    ui->actionSoustraction->setEnabled(true);
    ui->actionCombinaison->setEnabled(true);
    ui->actionMinimum->setEnabled(true);
    ui->actionMaximum->setEnabled(true);
    ui->actionAND->setEnabled(true);
    ui->actionOR->setEnabled(true);
    ui->actionXOR->setEnabled(true);
    ui->actionNOT->setEnabled(true);
}

void MainWindow::desactiverActionsBinaires() {
    //menu outils
    ui->actionAddition->setEnabled(false);
    ui->actionSoustraction->setEnabled(false);
    ui->actionCombinaison->setEnabled(false);
    ui->actionMinimum->setEnabled(false);
    ui->actionMaximum->setEnabled(false);
    ui->actionAND->setEnabled(false);
    ui->actionOR->setEnabled(false);
    ui->actionXOR->setEnabled(false);
    ui->actionNOT->setEnabled(false);
}



//menu fichier
void MainWindow::ouvrirImage (const char* nomFichier) {
    QImage loadImg (nomFichier);
    if (loadImg.isNull()) {
        statusBar()->showMessage(tr("Échec de lecture de l'image depuis le fichier: %1").arg(nomFichier));
        return;
    }

    ////OpenCV charge l'image
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).absolutePath()); /// /home.../TCIMAG_ressources/lena.bmp
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).canonicalPath());/// /home.../TCIMAG_ressources/lena.bmp
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).path());         /// ../TCIMAG_ressources/lena.bmp
    creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).dirName());        /// lena.bmp
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).homePath());     /// ~/
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).tempPath());     /// /tmp
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).rootPath());     /// /

    ////Qt charge l'imageToQPixmap()
    //creerFenetre (QPixmap::fromImage (loadImg), QDir (tr (nomFichier)).dirName());
}

void MainWindow::creerFenetre(const QPixmap& pixmap, const QString& titre = "") {
    if (pixmap.isNull())
        return;

    QLabel* labelImage = new QLabel();
    labelImage->setWindowFlags(Qt::FramelessWindowHint);
    labelImage->setMouseTracking(true);
    labelImage->installEventFilter(this);
    labelImage->show();
    labelImage->setScaledContents(true);
    labelImage->setFixedSize(pixmap.size());
    labelImage->setPixmap(pixmap);
    scaleFactor[qHash(labelImage)] = 1.0;
    windowTitle[qHash(labelImage)] = titre;
    if(dernierTempsDeCalcul != 0) {
        tempsCalcul[qHash(labelImage)] = dernierTempsDeCalcul;
        dernierTempsDeCalcul = 0;
    }

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(labelImage);
    scrollArea->installEventFilter(this);

    QMdiSubWindow* subWindow = new QMdiSubWindow();
    subWindow->setParent(centralWidget());
    subWindow->setWindowTitle(titre);
    subWindow->setMinimumSize ((int)(pixmap.width () / 5), (int)(pixmap.height () / 5));
    subWindow->setWidget(scrollArea);
    subWindow->show();
}

const QPixmap MainWindow::imageToQPixmap (const char* nomFichier) {
    cv::Mat loadImg;
    loadImg = cv::imread(nomFichier, CV_LOAD_IMAGE_COLOR);
    if (!loadImg.data) {
        statusBar()->showMessage(tr("Échec de lecture de l'image depuis le fichier: %1").arg(nomFichier));
        return QPixmap();
    }
    QImage rgbImg;
    cvMatToQImage(loadImg, rgbImg);
    return QPixmap::fromImage(rgbImg);
}

void MainWindow::fermerTout() {
    QList<QObject*> children = ui->centralWidget->children();
    if (children.isEmpty())
        return;
    QObject* child = findFirstChildOfType<QWidget>(children);
    if (child == NULL)
        return;
    children = child->children();
    if (children.isEmpty())
        return;
    QScrollArea* scrollArea;
    for (int i = 0; i < children.size(); i++) {
        scrollArea = findFirstChildOfType<QScrollArea>(children.at(i)->children());
        if (scrollArea == NULL)
            continue;
        scrollArea->close();
    }

}

void MainWindow::detruire(QScrollArea* scrollArea) {
    if (scrollArea == NULL)
        return;
    QLabel* label = getLabelInArea(scrollArea);
    windowTitle.remove(qHash(label));
    scaleFactor.remove(qHash(label));
    tempsCalcul.remove(qHash(label));
    label->deleteLater();
    scrollArea->deleteLater();
    scrollArea->parent()->deleteLater();
}

//menu affichage
void MainWindow::scaleImage (QScrollArea* scrollArea, double facteur) {
    QLabel* image = getLabelInArea(scrollArea);
    QSize actuelle = image->pixmap()->size();
    if (!this->scaleFactor.contains(qHash(image)))
        return;
    double scaleFactor = this->scaleFactor[qHash(image)] * facteur;
    this->scaleFactor[qHash(image)] = scaleFactor;

    image->setFixedSize(scaleFactor * actuelle);

    adjustScrollBar (scrollArea->horizontalScrollBar(), scaleFactor);
    adjustScrollBar (scrollArea->verticalScrollBar(), scaleFactor);

    updateZoomActions(image);
}

void MainWindow::adjustScrollBar (QScrollBar* scrollBar, double facteur) {
    scrollBar->setValue (int (facteur * scrollBar->value () + (facteur - 1) * scrollBar->pageStep () / 2));
}

void MainWindow::updateZoomActions (QLabel* image) {
    if (!scaleFactor.contains(qHash(image)))
        return;
    double scaleFactor = this->scaleFactor[qHash(image)];
    ui->actionZoomIn->setEnabled(scaleFactor < 3.0);
    ui->actionZoomOut->setEnabled(scaleFactor > 0.333);
}

void MainWindow::afficherPalette (QLabel* label, CodePalette code) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("Palette %1: ").arg(code == CVT_COLOR_INVERSE ? "cvtColor Inverse" : code == THERMAL ? "Thermal" : code == CVT_COLOR ? "cvtColor" : code == MRI ? "MRI" : code == COLD_TO_HOT ? "Cold-to-Hot" : code == JET ? "Jet" : "") + windowTitle[qHash(label)];
    calculerPalette (image, titre, code);
}

void MainWindow::calculerPalette (QImage& argbImage, QString titre, CodePalette code) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::Mat BlueLUT(1, 256, CV_8U);
    cv::Mat GreenLUT(1, 256, CV_8U);
    cv::Mat RedLUT(1, 256, CV_8U);
    uchar* p;

    switch (code) {
    case CVT_COLOR_INVERSE:
        p = BlueLUT.data;
        for(int i = 0; i < 88; ++i)
            p[i] = round(1/(3*0.114)*i);
        for(int i = 88; i < 175; ++i)
            p[i] = 255-round(1/(3*0.114)*i);
        for(int i = 175; i < 256; ++i)
            p[i] = round(1/(3*0.114)*i);

        p = GreenLUT.data;
        for(int i = 0; i < 256; ++i)
            p[i] = cv::saturate_cast<uchar>(1/(3*0.587)*i);

        p = RedLUT.data;
        for(int i = 0; i < 256; ++i)
            p[i] = cv::saturate_cast<uchar>(1/(3*0.299)*i);
        break;

    case THERMAL:
        p = BlueLUT.data;
        for(int i = 0; i < 15; ++i)
            p[i] = 90 * i/15;
        for(int i = 15; i < 195; ++i)
            p[i] = 90 - (i-15) * 90/180;
        for(int i = 195; i < 256; ++i)
            p[i] = 255 * (i-195)/180;

        p = GreenLUT.data;
        for(int i = 0; i < 15; ++i)
            p[i] = 0;
        for(int i = 15; i < 195; ++i)
            p[i] = 255 * (i-15)/180;
        for(int i = 195; i < 256; ++i)
            p[i] = 255;

        p = RedLUT.data;
        for(int i = 0; i < 25; ++i)
            p[i] = 90 * i/15;
        for(int i = 15; i < 195; ++i)
            p[i] = 90 + (i-15) * 155/180 + 11;
        for(int i = 195; i < 256; ++i)
            p[i] = 255;
        break;

    case CVT_COLOR:
        p = BlueLUT.data;
        for(int i = 0; i < 29; ++i)
            p[i] = 255;
        for(int i = 29; i < 179; ++i)
            p[i] = round(interpolatationLineaire(i, 255, 29, 0, 179));
        for(int i = 179; i < 256; ++i)
            p[i] = 0;

        p = GreenLUT.data;
        for(int i = 0; i < 29; ++i)
            p[i] = round(interpolatationLineaire(i, 0, 0, 255, 29));
        for(int i = 29; i < 179; ++i)
            p[i] = 255;
        for(int i = 179; i < 256; ++i)
            p[i] = round(interpolatationLineaire(i, 255, 179, 0, 255));

        p = RedLUT.data;
        for(int i = 0; i < 29; ++i)
            p[i] = 0;
        for(int i = 29; i < 179; ++i)
            p[i] = round(interpolatationLineaire(i, 0, 29, 255, 179));
        for(int i = 179; i < 256; ++i)
            p[i] = 255;
        break;

    case MRI:
        p = BlueLUT.data;
        for(int i = 0; i < 25; ++i)
            p[i] = 255 * i/25;
        for(int i = 25; i < 140; ++i)
            p[i] = 255 - (int)((i-25) * 255/115);
        for(int i = 140; i < 256; ++i)
            p[i] = 0;

        p = GreenLUT.data;
        for(int i = 0; i < 25; ++i)
            p[i] = 0;
        for(int i = 25; i < 140; ++i)
            p[i] = 255 * (i-25)/115;
        for(int i = 140; i < 256; ++i)
            p[i] = 255 - (int)((i-140) * 255/115);

        p = RedLUT.data;
        for(int i = 0; i < 25; ++i)
            p[i] = 0;
        for(int i = 25; i < 140; ++i)
            p[i] = 0;
        for(int i = 140; i < 256; ++i)
            p[i] = 255 * (i-140)/115;
        break;

    case COLD_TO_HOT:
        p = BlueLUT.data;
        for(int i = 0; i < 85; ++i)
            p[i] = 255;
        for(int i = 85; i < 170; ++i)
            p[i] = round(interpolatationLineaire(i, 255, 85, 0, 170));
        for(int i = 170; i < 256; ++i)
            p[i] = 0;

        p = GreenLUT.data;
        for(int i = 0; i < 85; ++i)
            p[i] = round(interpolatationLineaire(i, 0, 0, 255, 85));
        for(int i = 85; i < 170; ++i)
            p[i] = 255;
        for(int i = 170; i < 256; ++i)
            p[i] = round(interpolatationLineaire(i, 255, 170, 0, 255));

        p = RedLUT.data;
        for(int i = 0; i < 85;++i)
            p[i] = 0;
        for(int i = 85; i < 170; ++i)
            p[i] = round(interpolatationLineaire(i, 0, 85, 255, 170));
        for(int i = 170; i < 256; ++i)
            p[i] = 255;
        break;

    case JET:
        p = BlueLUT.data;
        for(int i = 0; i < 32; ++i)
            p[i] = round(interpolatationLineaire(i, 121, 0, 255,32));
        for(int i = 32; i < 99; ++i)
            p[i] = 255;
        for(int i = 99; i < 159; ++i)
            p[i] = round(interpolatationLineaire(i, 255, 99, 0, 159));
        for(int i = 159; i < 223; ++i)
            p[i] = 0;
        for(int i = 223; i < 256; ++i)
            p[i] = 0;

        p = GreenLUT.data;
        for(int i = 0; i < 32; ++i)
            p[i] = 0;
        for(int i = 32; i < 99; ++i)
            p[i] = round(interpolatationLineaire(i, 0, 32, 255, 99));
        for(int i = 99; i < 159; ++i)
            p[i] = 255;
        for(int i = 159; i < 223; ++i)
            p[i] = round(interpolatationLineaire(i, 255, 159, 0, 223));
        for(int i = 223; i < 256; ++i)
            p[i] = 0;

        p = RedLUT.data;
        for(int i = 0; i < 32; ++i)
            p[i] = 0;
        for(int i = 32; i < 99; ++i)
            p[i] = 0;
        for(int i = 99; i < 159; ++i)
            p[i] = round(interpolatationLineaire(i, 0, 99, 255, 159));
        for(int i = 159; i < 223; ++i)
            p[i] = 255;
        for(int i = 223; i < 256; ++i)
            p[i] = cv::saturate_cast<uchar>(interpolatationLineaire(i, 255, 223, 121, 255));
        break;
    }

    ///Debug
    //std::cerr << BlueLUT << std::endl;
    //std::cerr << GreenLUT << std::endl;
    //std::cerr << RedLUT << std::endl;

    std::vector<cv::Mat> bgr_planes;
    cv::split(bgrMat, bgr_planes);
    cv::LUT(bgr_planes[0], BlueLUT, bgr_planes[0], 0);
    cv::LUT(bgr_planes[1], GreenLUT, bgr_planes[1], 0);
    cv::LUT(bgr_planes[2], RedLUT, bgr_planes[2], 0);
    cv::merge(bgr_planes, bgrMat);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::dupliquer (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = windowTitle[qHash(label)];
    creerFenetre(QPixmap::fromImage(image), titre);
}

//menu outils
void MainWindow::afficherHistogramme (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("Histogramme pour: ") + windowTitle[qHash(label)];
    calculerHistogramme(image, titre);
}

void MainWindow::calculerHistogramme(QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    std::vector<cv::Mat> bgr_planes;
    split (bgrMat, bgr_planes);

    //// Establish the number of bins
    int histSize = 256;

    //// in CV_8UC3 the pixels values range from 0 to 255
    //// in CV_32FC3 the pixels values range from 0.0 to 1.0

    //// Set the ranges ( for B,G,R) )
    float range[] = { 0, 256 } ;
    const float* histRange = { range };

    bool uniform = true; bool accumulate = false;

    cv::Mat b_hist, g_hist, r_hist;

    //// Compute the histograms:
    cv::calcHist( &bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
    if (!argbImage.isGrayscale()) {
        cv::calcHist( &bgr_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
        cv::calcHist( &bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
    }


    //// Draw the histograms for B, G and R
    int hist_w = 512; int hist_h = 512;
    int bin_w = cvRound( (double) hist_w/histSize );

    cv::Mat histImage( hist_h, hist_w, CV_8UC3, !argbImage.isGrayscale() ? cv::Scalar::all(0) : cv::Scalar::all(191) );

    //// Normalize the result to [ 0, histImage.rows ]
    cv::normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
    if (!argbImage.isGrayscale()) {
        cv::normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
        cv::normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
    }


    std::string text;
    int fontFace = CV_FONT_HERSHEY_DUPLEX;
    double fontScale = 0.5;
    int thickness = 1;
    //// ligne de base : http://fr.wikipedia.org/wiki/Caract%C3%A8re_%28typographie%29
    //// i.e. limite inferieur de "l'oeil" du caractere
    int baseline=0;
    cv::Size textSize;
    cv::Point textOrg;
    cv::Scalar labelAxes;


    if (!argbImage.isGrayscale()) {
        labelAxes = cv::Scalar::all(255);


        cv::line(histImage, cv::Point(0, cvRound(histImage.rows/3)), cv::Point(histImage.cols, cvRound(histImage.rows/3)), labelAxes);
        cv::line(histImage, cv::Point(0, cvRound(histImage.rows*2/3)), cv::Point(histImage.cols, cvRound(histImage.rows*2/3)), labelAxes);

        //// Draw for each channel
        for(int i = 1; i < histSize; i++ ) {
            cv::line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                      cv::Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                      cv::Scalar( 255, 0, 0), 2, 8, 0  );
            cv::line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                      cv::Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                      cv::Scalar( 0, 255, 0), 2, 8, 0  );
            cv::line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                      cv::Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                      cv::Scalar( 0, 0, 255), 2, 8, 0  );
        }


        for(int i = 8; i < histImage.cols; i+=16)
            cv::line(histImage, cv::Point(i, histImage.rows - 4), cv::Point(i, histImage.rows), labelAxes);
        for(int i = 0; i < histImage.cols; i+=16)
            cv::line(histImage, cv::Point(i, histImage.rows - 6), cv::Point(i, histImage.rows), labelAxes);
        cv::line(histImage, cv::Point(cvRound(histImage.cols / 2), histImage.rows - 10), cv::Point(cvRound(histImage.cols / 2), histImage.rows), labelAxes);
        cv::line(histImage, cv::Point(cvRound(histImage.cols / 4), histImage.rows - 10), cv::Point(cvRound(histImage.cols / 4), histImage.rows), labelAxes);
        cv::line(histImage, cv::Point(cvRound(histImage.cols * 3 / 4), histImage.rows - 10), cv::Point(cvRound(histImage.cols * 3 / 4), histImage.rows), labelAxes);


        text = "255";
        baseline = 0;
        textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);
        baseline += thickness;
        // center the text
        textOrg = cv::Point(histImage.cols - textSize.width,
                      histImage.rows - textSize.height + baseline);
        // then put the text itself
        cv::putText(histImage, text, textOrg, fontFace, fontScale, labelAxes, thickness, 8);


        text = "0";
        baseline = 0;
        textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);
        baseline += thickness;
        // center the text
        textOrg = cv::Point(0,
                      histImage.rows - textSize.height + baseline);
        // then put the text itself
        cv::putText(histImage, text, textOrg, fontFace, fontScale, labelAxes, thickness, 8);


        text = "255";
        baseline = 0;
        textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);
        baseline += thickness;
        // center the text
        textOrg = cv::Point(0,
                      0 + textSize.height);
        // then put the text itself
        cv::putText(histImage, text, textOrg, fontFace, fontScale, labelAxes, thickness, 8);
    } else {
        labelAxes = cv::Scalar::all(95);


        cv::line(histImage, cv::Point(0, cvRound(histImage.rows/3)), cv::Point(histImage.cols, cvRound(histImage.rows/3)), labelAxes);
        cv::line(histImage, cv::Point(0, cvRound(histImage.rows*2/3)), cv::Point(histImage.cols, cvRound(histImage.rows*2/3)), labelAxes);


        //// Draw the channel
        for(int i = 1; i < histSize; i++ ) {
            cv::line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                      cv::Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                      cv::Scalar::all(31), 2, 8, 0  );
        }


        for(int i = 8; i < histImage.cols; i+=16)
            cv::line(histImage, cv::Point(i, histImage.rows - 4), cv::Point(i, histImage.rows), labelAxes);
        for(int i = 0; i < histImage.cols; i+=16)
            cv::line(histImage, cv::Point(i, histImage.rows - 6), cv::Point(i, histImage.rows), labelAxes);
        cv::line(histImage, cv::Point(cvRound(histImage.cols / 2), histImage.rows - 10), cv::Point(cvRound(histImage.cols / 2), histImage.rows), labelAxes);
        cv::line(histImage, cv::Point(cvRound(histImage.cols / 4), histImage.rows - 10), cv::Point(cvRound(histImage.cols / 4), histImage.rows), labelAxes);
        cv::line(histImage, cv::Point(cvRound(histImage.cols * 3 / 4), histImage.rows - 10), cv::Point(cvRound(histImage.cols * 3 / 4), histImage.rows), labelAxes);


        text = "255";
        baseline = 0;
        textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);
        baseline += thickness;
        // center the text
        textOrg = cv::Point(histImage.cols - textSize.width,
                      histImage.rows - textSize.height + baseline);
        // then put the text itself
        cv::putText(histImage, text, textOrg, fontFace, fontScale, labelAxes, thickness, 8);


        text = "0";
        baseline = 0;
        textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);
        baseline += thickness;
        // center the text
        textOrg = cv::Point(0,
                      histImage.rows - textSize.height + baseline);
        // then put the text itself
        cv::putText(histImage, text, textOrg, fontFace, fontScale, labelAxes, thickness, 8);


        text = "255";
        baseline = 0;
        textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);
        baseline += thickness;
        // center the text
        textOrg = cv::Point(0,
                      0 + textSize.height);
        // then put the text itself
        cv::putText(histImage, text, textOrg, fontFace, fontScale, labelAxes, thickness, 8);
    }
    cvMatToQImage(histImage, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherRecadrage (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("Recadrage: ") + windowTitle[qHash(label)];
    calculerRecadrage (image, titre);
}

void MainWindow::calculerRecadrage (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::normalize(bgrMat, bgrMat, 0, 255, CV_MINMAX);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherHistogrammeNegatif (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("Histogramme Négatif: ") + windowTitle[qHash(label)];
    calculerHistogrammeNegatif(image, titre);
}

void MainWindow::calculerHistogrammeNegatif (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    uchar lookup [256];
    for(int i = 0; i < 256; i++)
        lookup[i] = 255 - i;
    cv::MatIterator_<cv::Vec3b> it, end;
    for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
        (*it)[0] = lookup[(*it)[0]];
        (*it)[1] = lookup[(*it)[1]];
        (*it)[2] = lookup[(*it)[2]];
    }

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherCalibration (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    int seuil1, seuil2;
    bool ok;
    IntIntDialog d(this, QString("Calibration d'Histogramme"), QString("Min (entre 0 et 255): "), 80, 0, 255, 1, QString("Max (entre 0 et 255): "), 240, 0, 255, 1);
    d.run(seuil1, seuil2, ok);
    if (!ok) return;
    statusBar()->showMessage(tr("Calibration d'Histogramme(%1;%2): ").arg(seuil1).arg(seuil2));
    QString titre = QString("Calibration d'Histogramme(%1;%2): ").arg(seuil1).arg(seuil2) + windowTitle[qHash(label)];
    calculerCalibration(image, titre, seuil1, seuil2);
}

void MainWindow::calculerCalibration (QImage& argbImage, QString titre, double valeurMin, double valeurMax) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::normalize(bgrMat, bgrMat, valeurMin, valeurMax, CV_MINMAX);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherEgalisation (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("Égalisation: ") + windowTitle[qHash(label)];
    calculerEgalisation (image, titre);
}

void MainWindow::calculerEgalisation (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    std::vector<cv::Mat> bgr_planes;
    cv::split(bgrMat, bgr_planes);
    cv::equalizeHist(bgr_planes[0], bgr_planes[0]);
    cv::equalizeHist(bgr_planes[1], bgr_planes[1]);
    cv::equalizeHist(bgr_planes[2], bgr_planes[2]);
    cv::merge(bgr_planes,bgrMat);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherExponentielle (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    statusBar()->showMessage(tr("Exponentielle"));
    QString titre = QString("Exponentielle: ") + windowTitle[qHash(label)];
    calculerExponentielle(image, titre);
}

void MainWindow::calculerExponentielle (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    if (argbImage.isGrayscale()) {
        cv::cvtColor(bgrMat, bgrMat, CV_BGR2GRAY);
        bgrMat.convertTo(bgrMat, CV_64F, 1.d/255, 0);
        cv::exp(bgrMat, bgrMat);
        bgrMat -= 1.d;
        cv::normalize(bgrMat, bgrMat, 0, 1, CV_MINMAX);
        bgrMat.convertTo(bgrMat, CV_8U, 255, 0);
        cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);
    } else {
        bgrMat.convertTo(bgrMat, CV_64F, 1.d/255, 0);
        cv::exp(bgrMat, bgrMat);
        bgrMat -= 1.d;
        cv::normalize(bgrMat, bgrMat, 0, 1, CV_MINMAX);
        bgrMat.convertTo(bgrMat, CV_8U, 255, 0);
    }

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherLogarithmique (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    statusBar()->showMessage(tr("Logarithmique"));
    QString titre = QString("Logarithmique: ") + windowTitle[qHash(label)];
    calculerLogarithmique(image, titre);
}

void MainWindow::calculerLogarithmique (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    if (argbImage.isGrayscale()) {
        cv::cvtColor(bgrMat, bgrMat, CV_BGR2GRAY);
        bgrMat.convertTo(bgrMat, CV_64F, 1.d, 0);
        bgrMat += 1.d;
        cv::log(bgrMat, bgrMat);
        cv::normalize(bgrMat, bgrMat, 0, 1, CV_MINMAX);
        bgrMat.convertTo(bgrMat, CV_8U, 255, 0);
        cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);
    } else {
        bgrMat.convertTo(bgrMat, CV_64F, 1.d, 0);
        bgrMat += 1.d;
        cv::log(bgrMat, bgrMat);
        cv::normalize(bgrMat, bgrMat, 0, 1, CV_MINMAX);
        bgrMat.convertTo(bgrMat, CV_8U, 255, 0);
    }

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherAddition (QLabel* labelDroite, QLabel* labelGauche) {
    QImage imageGauche = labelGauche->pixmap()->toImage();
    QImage imageDroite = labelDroite->pixmap()->toImage();
    if (imageGauche.size() != imageDroite.size()) {
        QString msg = tr("L'addition n'est définie que pour des images de la même taille !");
        QErrorMessage err(this);
        err.showMessage(msg);
        err.exec();
        statusBar()->showMessage(msg);
        return;
    }
    QString titre = windowTitle[qHash(labelDroite)] + QString(" + ") + windowTitle[qHash(labelGauche)];
    calculerAddition(imageDroite, imageGauche, titre);
}

void MainWindow::calculerAddition (QImage& argbImageGauche, QImage& argbImageDroite, QString titre) {
    if (argbImageGauche.size() != argbImageDroite.size())
        return;
    cv::Mat bgrMatG;
    QImageTocvMat(argbImageGauche, bgrMatG);
    cv::Mat bgrMatD;
    QImageTocvMat(argbImageDroite, bgrMatD);

    double alpha = 0.5;
    cv::Mat dst;
    cv::addWeighted (bgrMatG, alpha, bgrMatD, 1 - alpha, 0.0, dst, -1);

    QImage result;
    cvMatToQImage(dst, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

void MainWindow::afficherSoustraction (QLabel* labelGauche, QLabel* labelDroite) {
    QImage imageGauche = labelGauche->pixmap()->toImage();
    QImage imageDroite = labelDroite->pixmap()->toImage();
    if (imageGauche.size() != imageDroite.size()) {
        QString msg = tr("La soustraction n'est définie que pour des images de la même taille !");
        QErrorMessage err(this);
        err.showMessage(msg);
        err.exec();
        statusBar()->showMessage(msg);
        return;
    }
    QString titre = windowTitle[qHash(labelGauche)] + QString(" - ") + windowTitle[qHash(labelDroite)];
    calculerSoustraction(imageGauche, imageDroite, titre);
}

void MainWindow::calculerSoustraction (QImage& argbImageGauche, QImage& argbImageDroite, QString titre) {
    if (argbImageGauche.size() != argbImageDroite.size())
        return;
    cv::Mat bgrMatG;
    QImageTocvMat(argbImageGauche, bgrMatG);
    cv::Mat bgrMatD;
    QImageTocvMat(argbImageDroite, bgrMatD);

    double alpha = 0.5;
    cv::Mat dst;
    cv::addWeighted (bgrMatG, alpha, bgrMatD, -1 + alpha, 127, dst, -1);

    QImage result;
    cvMatToQImage(dst, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

void MainWindow::afficherCombinaison (QLabel* labelGauche, QLabel* labelDroite) {
    QImage imageGauche = labelGauche->pixmap()->toImage();
    QImage imageDroite = labelDroite->pixmap()->toImage();
    if (imageGauche.size() != imageDroite.size()) {
        QString msg = tr("La combinaision n'est définie que pour des images de la même taille !");
        QErrorMessage err(this);
        err.showMessage(msg);
        err.exec();
        statusBar()->showMessage(msg);
        return;
    }
    bool ok;
    double alpha = QInputDialog::getDouble(this, tr("Combinaison"), tr("Pourcentage (entre 0 et 100): "), 50, 0, 100, 2, &ok, 0);
    if (!ok) return;
    statusBar()->showMessage(tr("Alpha = %1").arg(alpha));
    QString titre = QString("%1%").arg(alpha) +windowTitle[qHash(labelGauche)] + QString("+%1%").arg(100-alpha) + windowTitle[qHash(labelDroite)];
    calculerCombinaison (imageGauche, imageDroite, titre, alpha/100);
}

void MainWindow::calculerCombinaison (QImage& argbImageGauche, QImage& argbImageDroite, QString titre, double alpha) {
    if (argbImageGauche.size() != argbImageDroite.size())
        return;
    cv::Mat bgrMatG;
    QImageTocvMat(argbImageGauche, bgrMatG);
    cv::Mat bgrMatD;
    QImageTocvMat(argbImageDroite, bgrMatD);

    cv::Mat dst;
    cv::addWeighted (bgrMatG, alpha, bgrMatD, 1 - alpha, 0, dst, -1);

    QImage result;
    cvMatToQImage(dst, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

void MainWindow::afficherMinimum (QLabel* labelDroite, QLabel* labelGauche) {
    QImage imageGauche = labelGauche->pixmap()->toImage();
    QImage imageDroite = labelDroite->pixmap()->toImage();
    if (imageGauche.size() != imageDroite.size()) {
        QString msg = tr("Le minimum n'est définie que pour des images de la même taille !");
        QErrorMessage err(this);
        err.showMessage(msg);
        err.exec();
        statusBar()->showMessage(msg);
        return;
    }
    QString titre = QString("Min(%1,%2)").arg(windowTitle[qHash(labelDroite)]).arg(windowTitle[qHash(labelGauche)]);
    calculerMinimum(imageDroite, imageGauche, titre);
}

void MainWindow::calculerMinimum (QImage& argbImageGauche, QImage& argbImageDroite, QString titre) {
    if (argbImageGauche.size() != argbImageDroite.size())
        return;
    cv::Mat bgrMatG;
    QImageTocvMat(argbImageGauche, bgrMatG);
    cv::Mat bgrMatD;
    QImageTocvMat(argbImageDroite, bgrMatD);

    cv::Mat dst;cv::min(bgrMatG, bgrMatD, dst);

    QImage result;
    cvMatToQImage(dst, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

void MainWindow::afficherMaximum (QLabel* labelDroite, QLabel* labelGauche) {
    QImage imageGauche = labelGauche->pixmap()->toImage();
    QImage imageDroite = labelDroite->pixmap()->toImage();
    if (imageGauche.size() != imageDroite.size()) {
        QString msg = tr("Le maximum n'est définie que pour des images de la même taille !");
        QErrorMessage err(this);
        err.showMessage(msg);
        err.exec();
        statusBar()->showMessage(msg);
        return;
    }
    QString titre = QString("Max(%1,%2)").arg(windowTitle[qHash(labelDroite)]).arg(windowTitle[qHash(labelGauche)]);
    calculerMaximum(imageDroite, imageGauche, titre);
}

void MainWindow::calculerMaximum (QImage& argbImageGauche, QImage& argbImageDroite, QString titre) {
    if (argbImageGauche.size() != argbImageDroite.size())
        return;
    cv::Mat bgrMatG;
    QImageTocvMat(argbImageGauche, bgrMatG);
    cv::Mat bgrMatD;
    QImageTocvMat(argbImageDroite, bgrMatD);

    cv::Mat dst;cv::max(bgrMatG, bgrMatD, dst);

    QImage result;
    cvMatToQImage(dst, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

void MainWindow::afficherAND (QLabel* labelDroite, QLabel* labelGauche) {
    QImage imageGauche = labelGauche->pixmap()->toImage();
    QImage imageDroite = labelDroite->pixmap()->toImage();
    if (imageGauche.size() != imageDroite.size()) {
        QString msg = tr("L'opérateur AND n'est définie que pour des images de la même taille !");
        QErrorMessage err(this);
        err.showMessage(msg);
        err.exec();
        statusBar()->showMessage(msg);
        return;
    }
    QString titre = windowTitle[qHash(labelDroite)] + QString(" AND ") + windowTitle[qHash(labelGauche)];
    calculerAND(imageDroite, imageGauche, titre);
}

void MainWindow::calculerAND (QImage& argbImageGauche, QImage& argbImageDroite, QString titre) {
    if (argbImageGauche.size() != argbImageDroite.size())
        return;
    cv::Mat bgrMatG;
    QImageTocvMat(argbImageGauche, bgrMatG);
    cv::Mat bgrMatD;
    QImageTocvMat(argbImageDroite, bgrMatD);

    cv::Mat dst; cv::bitwise_and(bgrMatG, bgrMatD, dst, cv::noArray());

    QImage result;
    cvMatToQImage(dst, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

void MainWindow::afficherOR (QLabel* labelDroite, QLabel* labelGauche) {
    QImage imageGauche = labelGauche->pixmap()->toImage();
    QImage imageDroite = labelDroite->pixmap()->toImage();
    if (imageGauche.size() != imageDroite.size()) {
        QString msg = tr("L'opérateur OR n'est définie que pour des images de la même taille !");
        QErrorMessage err(this);
        err.showMessage(msg);
        err.exec();
        statusBar()->showMessage(msg);
        return;
    }
    QString titre = windowTitle[qHash(labelDroite)] + QString(" OR ") + windowTitle[qHash(labelGauche)];
    calculerOR(imageDroite, imageGauche, titre);
}

void MainWindow::calculerOR (QImage& argbImageGauche, QImage& argbImageDroite, QString titre) {
    if (argbImageGauche.size() != argbImageDroite.size())
        return;
    cv::Mat bgrMatG;
    QImageTocvMat(argbImageGauche, bgrMatG);
    cv::Mat bgrMatD;
    QImageTocvMat(argbImageDroite, bgrMatD);

    cv::Mat dst; cv::bitwise_or(bgrMatG, bgrMatD, dst, cv::noArray());

    QImage result;
    cvMatToQImage(dst, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

void MainWindow::afficherXOR (QLabel* labelDroite, QLabel* labelGauche) {
    QImage imageGauche = labelGauche->pixmap()->toImage();
    QImage imageDroite = labelDroite->pixmap()->toImage();
    if (imageGauche.size() != imageDroite.size()) {
        QString msg = tr("L'opérateur XOR n'est définie que pour des images de la même taille !");
        QErrorMessage err(this);
        err.showMessage(msg);
        err.exec();
        statusBar()->showMessage(msg);
        return;
    }
    QString titre = windowTitle[qHash(labelDroite)] + QString(" XOR ") + windowTitle[qHash(labelGauche)];
    calculerXOR(imageDroite, imageGauche, titre);
}

void MainWindow::calculerXOR (QImage& argbImageGauche, QImage& argbImageDroite, QString titre) {
    if (argbImageGauche.size() != argbImageDroite.size())
        return;
    cv::Mat bgrMatG;
    QImageTocvMat(argbImageGauche, bgrMatG);
    cv::Mat bgrMatD;
    QImageTocvMat(argbImageDroite, bgrMatD);

    cv::Mat dst; cv::bitwise_xor(bgrMatG, bgrMatD, dst, cv::noArray());

    QImage result;
    cvMatToQImage(dst, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

void MainWindow::afficherNOT (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("NOT: ") + windowTitle[qHash(label)];
    calculerNOT(image, titre);
}

void MainWindow::calculerNOT (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::bitwise_not(bgrMat, bgrMat, cv::noArray());

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherPlanBinaire (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int bit = QInputDialog::getInt(this, tr("Plan Binaire"), tr("Bit (entre 1 et 8): "), 4, 1, 8, 1, &ok, 0);
    if (!ok) return;
    statusBar()->showMessage(tr("Plan Binaire(%1): ").arg(bit));
    QString titre = QString("Plan Binaire(%1): ").arg(bit) + windowTitle[qHash(label)];
    calculerPlanBinaire(image, titre, bit);
}

void MainWindow::calculerPlanBinaire (QImage& argbImage, QString titre, int bit) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);
    int masque = 255&(1<<(bit-1));

    cv::MatIterator_<cv::Vec3b> it, end;
    for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
        (*it)[0] = (*it)[0] & masque;
        (*it)[1] = (*it)[1] & masque;
        (*it)[2] = (*it)[2] & masque;
    }

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherQuantification (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int bits = QInputDialog::getInt(this, tr("Quantification"), tr("Bits gardés (entre 1 et 8): "), 4, 1, 8, 1, &ok, 0);
    if (!ok) return;
    statusBar()->showMessage(tr("Quantification(%1 bits): ").arg(bits));
    QString titre = QString("Quantification(%1 bits): ").arg(bits) + windowTitle[qHash(label)];
    calculerQuantification(image, titre, bits);
}

void MainWindow::calculerQuantification (QImage& argbImage, QString titre, int bits) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);
    int masque = (255>>(8-bits))<<(8-bits);

    cv::MatIterator_<cv::Vec3b> it, end;
    for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
        (*it)[0] = (*it)[0] & masque;
        (*it)[1] = (*it)[1] & masque;
        (*it)[2] = (*it)[2] & masque;
    }

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherChangementDEchelle (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    int width = image.width(), height = image.height();
    int dimX, dimY;
    bool ok;
    IntIntDialog d(this, QString("Changement d'Échelle"), QString("Dimension X (entre 1 et %1): ").arg(width*10), width, 1, width*10, 1, QString("Dimension Y (entre 1 et %1): ").arg(height*10), height, 1, height*10, 1);
    d.run(dimX, dimY, ok);
    if (!ok) return;
    statusBar()->showMessage(tr("Changement d'Échelle(%1;%2): ").arg(dimX).arg(dimY));
    QString titre = QString("Changement d'Échelle(%1;%2): ").arg(dimX).arg(dimY) + windowTitle[qHash(label)];
    calculerChangementDEchelle (image, titre, dimX, dimY);
}

void MainWindow::calculerChangementDEchelle (QImage& argbImage, QString titre, int dimX, int dimY) {
   cv::Mat bgrMat;
   QImageTocvMat(argbImage, bgrMat);

   cv::Mat transform;
   ///void resize(InputArray src, OutputArray dst, Size dsize, double fx=0, double fy=0, int interpolation=INTER_LINEAR )
   cv::resize(bgrMat, transform, cv::Size(dimX, dimY), 0, 0, cv::INTER_LANCZOS4);
   bgrMat=transform;

   cvMatToQImage(bgrMat, argbImage);
   creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherRotation (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    double angle;
    double zoom;
    bool ok;
    DoubleDoubleDialog d(this, QString("Rotation"), QString("Angle (entre 0 et 360): "), 0, 0, 360, 2, QString("Zoom (entre 0 et 10): "), 1, 0, 10, 2);
    d.run(angle, zoom, ok);
    if (!ok) return;
    statusBar()->showMessage(tr("Rotation(%1°;%2): ").arg(angle).arg(zoom));
    QString titre = QString("Rotation(%1°;%2): ").arg(angle).arg(zoom) + windowTitle[qHash(label)];
    calculerRotation (image, titre, angle, zoom);
}

void MainWindow::calculerRotation (QImage& argbImage, QString titre, double angle, double zoom) {
   cv::Mat bgrMat;
   QImageTocvMat(argbImage, bgrMat);

   cv::Mat rot_mat( 2, 3, CV_32FC1 );
   /// Compute a rotation matrix with respect to the center of the image
   cv::Point center = cv::Point( bgrMat.cols/2, bgrMat.rows/2 );
   /// Get the rotation matrix with the specifications above
   rot_mat = cv::getRotationMatrix2D( center, angle, zoom );
   /// Rotate the warped image
   cv::warpAffine( bgrMat, bgrMat, rot_mat, bgrMat.size(), cv::INTER_NEAREST, cv::BORDER_CONSTANT, cv::Scalar() );

   cvMatToQImage(bgrMat, argbImage);
   creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherRotationInterpolee (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    double angle;
    double zoom;
    bool ok;
    DoubleDoubleDialog d(this, QString("Rotation Interpolée"), QString("Angle (entre 0 et 360): "), 0, 0, 360, 2, QString("Zoom (entre 0 et 10): "), 1, 0, 10, 2);
    d.run(angle, zoom, ok);
    if (!ok) return;
    statusBar()->showMessage(tr("Rotation Interpolée(%1°;%2): ").arg(angle).arg(zoom));
    QString titre = QString("Rotation Interpolée(%1°;%2): ").arg(angle).arg(zoom) + windowTitle[qHash(label)];
    calculerRotationInterpolee (image, titre, angle, zoom);
}

void MainWindow::calculerRotationInterpolee (QImage& argbImage, QString titre, double angle, double zoom) {
   cv::Mat bgrMat;
   QImageTocvMat(argbImage, bgrMat);

   cv::Mat rot_mat( 2, 3, CV_32FC1 );
   /// Compute a rotation matrix with respect to the center of the image
   cv::Point center = cv::Point( bgrMat.cols/2, bgrMat.rows/2 );
   /// Get the rotation matrix with the specifications above
   rot_mat = cv::getRotationMatrix2D( center, angle, zoom );
   /// Rotate the warped image cf opencv/modules/imgproc/src/imgwarp.cpp ln 3265
   cv::warpAffine( bgrMat, bgrMat, rot_mat, bgrMat.size(), cv::INTER_LANCZOS4, cv::BORDER_CONSTANT, cv::Scalar() );

   cvMatToQImage(bgrMat, argbImage);
   creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherTransposee (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("Transposée: ") + windowTitle[qHash(label)];
    calculerTransposee (image, titre);
}

void MainWindow::calculerTransposee (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    bgrMat = bgrMat.t();

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherVuePerspective (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("Vue Perspective: ") + windowTitle[qHash(label)];
    calculerVuePerspective (image, titre);
}

void MainWindow::calculerVuePerspective (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::Point2f srcTri[3];
    cv::Point2f dstTri[3];

    //cv::Mat rot_mat( 2, 3, CV_32FC1 );
    cv::Mat warp_mat( 2, 3, CV_32FC1 );
    cv::Mat src, warp_dst;//, warp_rotate_dst;

    /// Load the image
    //src = cv::imread( argv[1], 1 );
    src = bgrMat;

    /// Set the dst image the same type and size as src
    warp_dst = cv::Mat::zeros( src.rows, src.cols, src.type() );

    /// Set your 3 points to calculate the  Affine Transform
    srcTri[0] = cv::Point2f( 0,0 );
    srcTri[1] = cv::Point2f( src.cols - 1, 0 );
    srcTri[2] = cv::Point2f( 0, src.rows - 1 );

    dstTri[0] = cv::Point2f( src.cols*0.0, src.rows*0.33 );
    dstTri[1] = cv::Point2f( src.cols*0.85, src.rows*0.25 );
    dstTri[2] = cv::Point2f( src.cols*0.15, src.rows*0.7 );

    /// Get the Affine Transform
    //warp_mat = cv::getAffineTransform( srcTri, dstTri );
    warp_mat = cv::getPerspectiveTransform( srcTri, dstTri );

    /// Apply the Affine Transform just found to the src image
    //cv::warpAffine(src, warp_dst, warp_mat, warp_dst.size());
    cv::warpPerspective(src, warp_dst, warp_mat, warp_dst.size(), cv::INTER_LANCZOS4, BORDER_TYPE, cv::Scalar());
    bgrMat = warp_dst;

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherBruitUniforme (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int valeur = QInputDialog::getInt(this, tr("Bruit Uniforme"), tr("Valeur (entre 0 et 255): "), 20, 0, 255, 1, &ok, 0);
    if (!ok) return;
    statusBar()->showMessage(tr("Bruit Uniforme(%1): ").arg(valeur));
    QString titre = QString("Bruit Uniforme(%1): ").arg(valeur) + windowTitle[qHash(label)];
    calculerBruitUniforme (image, titre, valeur);
}

void MainWindow::calculerBruitUniforme (QImage& argbImage, QString titre, int valeur) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    int rows = bgrMat.rows;
    int cols = bgrMat.cols * bgrMat.channels();
    if (bgrMat.isContinuous()) {
        cols *= rows;
        rows = 1;
    }
    valeur++;
    uchar v;
    uchar* p;
    for (int i = 0; i < rows; i++) {
        p = bgrMat.ptr<uchar>(i);
        for (int j = 0; j < cols; j+=3) {
            v = rng.uniform(0, valeur);
            *(p + j + 0) = (*(p + j + 0)+v)%256;
            *(p + j + 1) = (*(p + j + 1)+v)%256;
            *(p + j + 2) = (*(p + j + 2)+v)%256;
        }
    }

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherBruitPoivreEtSel (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    double pourcentage = QInputDialog::getDouble(this, tr("Bruit Poivre et Sel"), tr("Pourcentage (entre 0 et 100): "), 10, 0, 100, 2, &ok, 0);
    if (!ok) return;
    statusBar()->showMessage(tr("Poivre et Sel(%1%): ").arg(pourcentage));
    QString titre = QString("Poivre et Sel(%1%): ").arg(pourcentage) + windowTitle[qHash(label)];
    calculerBruitPoivreEtSel (image, titre, pourcentage/100);
}

void MainWindow::calculerBruitPoivreEtSel (QImage& argbImage, QString titre, double pourcentage) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    int rows = bgrMat.rows;
    int cols = bgrMat.cols * bgrMat.channels();
    if (bgrMat.isContinuous()) {
        cols *= rows;
        rows = 1;
    }
    int n = pourcentage*cols/bgrMat.channels();
    if (n == 0) {
        creerFenetre(QPixmap::fromImage(argbImage), titre);
        return;
    }
    int cols_no_channels = (int)cols/bgrMat.channels();
    unsigned long int pixels[n];
    for (int i = 0; i < n; i++) {
        pixels[i] = rng.uniform(0, cols_no_channels);
    }
    std::sort(pixels, pixels + sizeof(pixels) / sizeof(pixels[0]));
    uchar v;
    uchar* p = bgrMat.ptr<uchar>(0);
    for (int i = 0; i < n; i++) {
        v = rng.next()%2?0:255;
        *(p + pixels[i]*3 + 0) = v;
        *(p + pixels[i]*3 + 1) = v;
        *(p + pixels[i]*3 + 2) = v;
    }

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherUniforme () {
    QImage image(256, 256, QImage::Format_RGB888);
    bool ok;
    int valeur = QInputDialog::getInt(this, tr("Image Uniforme"), tr("Valeur (entre 0 et 255)"), 0, 0, 255, 1, &ok, 0);
    if (!ok) return;
    statusBar()->showMessage(tr("Image Uniforme(%1)").arg(valeur));
    QString titre = QString("Image Uniforme(%1)").arg(valeur);
    calculerUniforme(image, titre, valeur);
}

void MainWindow::afficherUniforme (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int valeur = QInputDialog::getInt(this, tr("Image Uniforme"), tr("Valeur (entre 0 et 255)"), 0, 0, 255, 1, &ok, 0);
    if (!ok) return;
    statusBar()->showMessage(tr("Image Uniforme(%1)").arg(valeur));
    QString titre = QString("Image Uniforme(%1): ").arg(valeur) + windowTitle[qHash(label)];
    calculerUniforme(image, titre, valeur);
}

void MainWindow::calculerUniforme (QImage& argbImage, QString titre, int valeur) {
    cv::Mat bgrMat(argbImage.height(), argbImage.width(), CV_8UC3, cv::Scalar::all(valeur));

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherRampe () {
    QImage image(256, 256, QImage::Format_RGB888);
    QString titre = QString("Rampe");
    calculerRampe(image, titre);
}

void MainWindow::afficherRampe (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("Rampe");
    calculerRampe(image, titre);
}

void MainWindow::calculerRampe (QImage& argbImage, QString titre) {
    cv::Mat bgrMat(argbImage.height(), argbImage.width(), CV_8UC3, cv::Scalar(127, 0, 255));

    int rows = bgrMat.rows;
    int cols = bgrMat.cols * bgrMat.channels();
    uchar v = 0; uchar* p = (uchar*)bgrMat.data;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols-1; j+=3) {
            v = round(255*((cols-1.)-j)/(cols-1.));
            *(p + i*cols+j + 0) = v;
            *(p + i*cols+j + 1) = v;
            *(p + i*cols+j + 2) = v;
        }
    }

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

//menu filtrage
void MainWindow::afficherMoyenneur3x3 (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("Moyenneur 3x3: ") + windowTitle[qHash(label)];
    uint64 t0 = cv::getTickCount();
    image = calculerMoyenneur3x3  (image, cv::Point(-1,-1), BORDER_TYPE);
    double t = 1000 * (cv::getTickCount() - t0)/cv::getTickFrequency();
    dernierTempsDeCalcul = t;
    creerFenetre(QPixmap::fromImage(image), titre);
}

const QImage& MainWindow::calculerMoyenneur3x3 (const QImage& argbImage, cv::Point anchor, int borderType) {
    static cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    int ksize = 3;
    cv::Mat res;
    cv::filter2D(bgrMat, res, CV_16UC3, cv::Mat::ones(ksize, ksize, CV_8UC1), anchor, 0, borderType);
    res *= 1./(ksize*ksize);
    res.convertTo(bgrMat, CV_8U, 1, 0);

    static QImage result;
    cvMatToQImage(bgrMat, result);
    return result;
}

void MainWindow::afficherMoyenneurNxN (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int N = QInputDialog::getInt(this, tr("Moyenneur NxN séparable"), tr("N: "), 3, 3, 31, 1, &ok, 0);
    if (!ok) return;
    statusBar()->showMessage(tr("Moyenneur %1x%2 séparable: ").arg(N).arg(N));
    QString titre = QString("Moyenneur %1x%2 séparable: ").arg(N).arg(N) + windowTitle[qHash(label)];
    uint64 t0 = cv::getTickCount();
    image = calculerMoyenneurNxN (image, cv::Size (N, N), cv::Point (-1, -1), BORDER_TYPE);
    double t = 1000 * (cv::getTickCount() - t0)/cv::getTickFrequency();
    dernierTempsDeCalcul = t;
    creerFenetre(QPixmap::fromImage(image), titre);
}

const QImage& MainWindow::calculerMoyenneurNxN (const QImage& argbImage, cv::Size ksize, cv::Point anchor, int borderType) {
    static cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::blur (bgrMat, bgrMat, ksize, anchor, borderType);

    static QImage result;
    cvMatToQImage(bgrMat, result);
    return result;
}

void MainWindow::afficherLaplacien (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    double gain;
    int offset;
    bool ok;
    DoubleIntDialog d(this, QString("Laplacien"), QString("Gain (entre 1 et 30): "), 1, 1, 30, 2, QString("Offset (entre 0 et 255): "), 0, 0, 255, 1);
    d.run(gain, offset, ok);
    if (!ok) return;
    statusBar()->showMessage(tr("Laplacien(%1;%2): ").arg(gain).arg(offset));
    QString titre = QString("Laplacien(%1;%2): ").arg(gain).arg(offset) + windowTitle[qHash(label)];
    calculerLaplacien(image, titre, 3, gain, offset, BORDER_TYPE);
}

void MainWindow::calculerLaplacien (QImage& argbImage, QString titre, int ksize, double gain, double offset, int borderType) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::GaussianBlur(bgrMat, bgrMat, cv::Size(3,3), 0, 0, borderType);
    cv::Mat gMat;
    cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
    cv::Mat dst;
    cv::Laplacian (gMat, dst, CV_16S, ksize, gain, offset, borderType);
    cv::convertScaleAbs(dst, bgrMat);
    cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherMedian (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int N = QInputDialog::getInt(this, tr("Filtre Médian"), tr("N: "), 3, 3, 31, 2, &ok, 0);
    if (!ok) return;
    statusBar()->showMessage(tr("Filtre Médian %1x%2").arg(N).arg(N));
    QString titre = QString("Filtre Médian %1x%2: ").arg(N).arg(N) + windowTitle[qHash(label)];
    calculerMedian(image, titre, N);
}

void MainWindow::calculerMedian (QImage& argbImage, QString titre, int ksize) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::medianBlur(bgrMat, bgrMat, ksize);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::
afficherVFiltre (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int N = QInputDialog::getInt(this, tr("V-Filtre"), tr("Taille de la fenêtre: "), 3, 3, 31, 2, &ok, 0);
    if (!ok) return;
    statusBar()->showMessage(tr("V-Filtre(%1): ").arg(N));
    QString titre = QString("V-Filtre(%1): ").arg(N) + windowTitle[qHash(label)];
    calculerVFiltre(image, titre, N);
}

void MainWindow::calculerVFiltre (QImage& argbImage, QString titre, int ksize) {
    if (ksize % 2 == 0)
        return;
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    //if (argbImage.isGrayscale()) {
        cv::Mat gMat;
        cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
        int rows = gMat.rows, cols = gMat.cols;
        int size = (ksize - 1)/2;
        double best_mean, best_stddev, mean, stddev;
        cv::Mat result = gMat.clone();
        uchar* p = (uchar*)result.data;
        for (int y = 0; y < ksize-1; y++) {
            for (int x = 0; x < ksize-1; x++) {
                cv::Mat q0(gMat, cv::Rect(0, 0, x+1, y+1));       // Top-Left
                cv::Mat q1(gMat, cv::Rect(x, 0, ksize, y+1));     // Top-Right
                cv::Mat q2(gMat, cv::Rect(0, y, x+1, ksize));     // Bottom-Left
                cv::Mat q3(gMat, cv::Rect(x, y, ksize, ksize));   // Bottom-Right
                cv::Mat q4(gMat, cv::Rect(0, 0, size+1, size+1)); // Center
                cv::Mat mean_m, stddev_m, q;
                best_mean = -1; best_stddev = 1.79769e+308;

                for (int k = 0; k < 5; k++) {
                    q = k==0 ? q0 : k==1 ? q1 : k==2 ? q2 : k==3 ? q3 : q4;
                    cv::meanStdDev(q, mean_m, stddev_m, cv::noArray());
                    mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                    if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                }

                *(p + y*cols+x) = best_mean;
            }
        }
        for (int y = 0; y < ksize-1; y++) {
            for (int x = ksize-1; x < cols - ksize+1; x++) {
                cv::Mat q0(gMat, cv::Rect(x-ksize+1, 0, ksize, y+1));   // Top-Left
                cv::Mat q1(gMat, cv::Rect(x, 0, ksize, y+1));           // Top-Right
                cv::Mat q2(gMat, cv::Rect(x-ksize+1, y, ksize, ksize)); // Bottom-Left
                cv::Mat q3(gMat, cv::Rect(x, y, ksize, ksize));         // Bottom-Right
                cv::Mat q4(gMat, cv::Rect(x-size, 0, ksize, size+1));   // Center
                cv::Mat mean_m, stddev_m, q;
                best_mean = -1; best_stddev = 1.79769e+308;

                for (int k = 0; k < 5; k++) {
                    q = k==0 ? q0 : k==1 ? q1 : k==2 ? q2 : k==3 ? q3 : q4;
                    cv::meanStdDev(q, mean_m, stddev_m, cv::noArray());
                    mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                    if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                }

                *(p + y*cols+x) = best_mean;
            }
        }
        for (int y = 0; y < ksize-1; y++) {
            for (int x = cols - ksize+1; x < cols; x++) {
                cv::Mat q0(gMat, cv::Rect(x-ksize+1, 0, ksize, y+1));       // Top-Left
                cv::Mat q1(gMat, cv::Rect(x, 0, cols-x, y+1));              // Top-Right
                cv::Mat q2(gMat, cv::Rect(x-ksize+1, y, ksize, ksize));     // Bottom-Left
                cv::Mat q3(gMat, cv::Rect(x, y, cols-x, ksize));            // Bottom-Right
                cv::Mat q4(gMat, cv::Rect(x-size, 0, cols-x+size, size+1)); // Center
                cv::Mat mean_m, stddev_m, q;
                best_mean = -1; best_stddev = 1.79769e+308;

                for (int k = 0; k < 5; k++) {
                    q = k==0 ? q0 : k==1 ? q1 : k==2 ? q2 : k==3 ? q3 : q4;
                    cv::meanStdDev(q, mean_m, stddev_m, cv::noArray());
                    mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                    if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                }

                *(p + y*cols+x) = best_mean;
            }
        }



        for (int y = ksize-1; y < rows - ksize+1; y++) {
            for (int x = 0; x < ksize-1; x++) {
                cv::Mat q0(gMat, cv::Rect(0, y-ksize+1, x+1, ksize));   // Top-Left
                cv::Mat q1(gMat, cv::Rect(x, y-ksize+1, ksize, ksize)); // Top-Right
                cv::Mat q2(gMat, cv::Rect(0, y, x+1, ksize));           // Bottom-Left
                cv::Mat q3(gMat, cv::Rect(x, y, ksize, ksize));         // Bottom-Right
                cv::Mat q4(gMat, cv::Rect(0, y-size, size+1, ksize));   // Center
                cv::Mat mean_m, stddev_m, q;
                best_mean = -1; best_stddev = 1.79769e+308;

                for (int k = 0; k < 5; k++) {
                    q = k==0 ? q0 : k==1 ? q1 : k==2 ? q2 : k==3 ? q3 : q4;
                    cv::meanStdDev(q, mean_m, stddev_m, cv::noArray());
                    mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                    if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                }

                *(p + y*cols+x) = best_mean;
            }
        }
        for (int y = ksize-1; y < rows - ksize+1; y++) {
            for (int x = ksize-1; x < cols - ksize+1; x++) {
                cv::Mat q0(gMat, cv::Rect(x-ksize+1, y-ksize+1, ksize, ksize)); // Top-Left
                cv::Mat q1(gMat, cv::Rect(x, y-ksize+1, ksize, ksize));         // Top-Right
                cv::Mat q2(gMat, cv::Rect(x-ksize+1, y, ksize, ksize));         // Bottom-Left
                cv::Mat q3(gMat, cv::Rect(x, y, ksize, ksize));                 // Bottom-Right
                cv::Mat q4(gMat, cv::Rect(x-size, y-size, ksize, ksize));       // Center
                cv::Mat mean_m, stddev_m, q;
                best_mean = -1; best_stddev = 1.79769e+308;

                for (int k = 0; k < 5; k++) {
                    q = k==0 ? q0 : k==1 ? q1 : k==2 ? q2 : k==3 ? q3 : q4;
                    cv::meanStdDev(q, mean_m, stddev_m, cv::noArray());
                    mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                    if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                }

                *(p + y*cols+x) = best_mean;
            }
        }
        for (int y = ksize-1; y < rows - ksize+1; y++) {
            for (int x = cols - ksize+1; x < cols; x++) {
                cv::Mat q0(gMat, cv::Rect(x-ksize+1, y-ksize+1, ksize, ksize)); // Top-Left
                cv::Mat q1(gMat, cv::Rect(x, y-ksize+1, cols-x, ksize));        // Top-Right
                cv::Mat q2(gMat, cv::Rect(x-ksize+1, y, ksize, ksize));         // Bottom-Left
                cv::Mat q3(gMat, cv::Rect(x, y, cols-x, ksize));                // Bottom-Right
                cv::Mat q4(gMat, cv::Rect(x-size, y-size, cols-x+size, ksize)); // Center
                cv::Mat mean_m, stddev_m, q;
                best_mean = -1; best_stddev = 1.79769e+308;

                for (int k = 0; k < 5; k++) {
                    q = k==0 ? q0 : k==1 ? q1 : k==2 ? q2 : k==3 ? q3 : q4;
                    cv::meanStdDev(q, mean_m, stddev_m, cv::noArray());
                    mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                    if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                }

                *(p + y*cols+x) = best_mean;
            }
        }



        for (int y = cols - ksize+1; y < cols; y++) {
            for (int x = 0; x < ksize-1; x++) {
                cv::Mat q0(gMat, cv::Rect(0, y-ksize+1, x+1, ksize));       // Top-Left
                cv::Mat q1(gMat, cv::Rect(x, y-ksize+1, ksize, ksize));     // Top-Right
                cv::Mat q2(gMat, cv::Rect(0, y, x+1, cols-y));              // Bottom-Left
                cv::Mat q3(gMat, cv::Rect(x, y, ksize, cols-y));            // Bottom-Right
                cv::Mat q4(gMat, cv::Rect(0, y-size, size+1, cols-y+size)); // Center
                cv::Mat mean_m, stddev_m, q;
                best_mean = -1; best_stddev = 1.79769e+308;

                for (int k = 0; k < 5; k++) {
                    q = k==0 ? q0 : k==1 ? q1 : k==2 ? q2 : k==3 ? q3 : q4;
                    cv::meanStdDev(q, mean_m, stddev_m, cv::noArray());
                    mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                    if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                }

                *(p + y*cols+x) = best_mean;
            }
        }
        for (int y = cols - ksize+1; y < cols; y++) {
            for (int x = ksize-1; x < cols - ksize+1; x++) {
                cv::Mat q0(gMat, cv::Rect(x-ksize+1, y-ksize+1, ksize, ksize)); // Top-Left
                cv::Mat q1(gMat, cv::Rect(x, y-ksize+1, ksize, ksize));         // Top-Right
                cv::Mat q2(gMat, cv::Rect(x-ksize+1, y, ksize, cols-y));        // Bottom-Left
                cv::Mat q3(gMat, cv::Rect(x, y, ksize, cols-y));                // Bottom-Right
                cv::Mat q4(gMat, cv::Rect(x-size, y-size, ksize, cols-y+size)); // Center
                cv::Mat mean_m, stddev_m, q;
                best_mean = -1; best_stddev = 1.79769e+308;

                for (int k = 0; k < 5; k++) {
                    q = k==0 ? q0 : k==1 ? q1 : k==2 ? q2 : k==3 ? q3 : q4;
                    cv::meanStdDev(q, mean_m, stddev_m, cv::noArray());
                    mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                    if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                }

                *(p + y*cols+x) = best_mean;
            }
        }
        for (int y = cols - ksize+1; y < cols; y++) {
            for (int x = cols - ksize+1; x < cols; x++) {
                cv::Mat q0(gMat, cv::Rect(x-ksize+1, y-ksize+1, ksize, ksize));       // Top-Left
                cv::Mat q1(gMat, cv::Rect(x, y-ksize+1, cols-x, ksize));              // Top-Right
                cv::Mat q2(gMat, cv::Rect(x-ksize+1, y, ksize, cols-y));              // Bottom-Left
                cv::Mat q3(gMat, cv::Rect(x, y, cols-x, cols-y));                     // Bottom-Right
                cv::Mat q4(gMat, cv::Rect(x-size, y-size, cols-x+size, cols-y+size)); // Center
                cv::Mat mean_m, stddev_m, q;
                best_mean = -1; best_stddev = 1.79769e+308;

                for (int k = 0; k < 5; k++) {
                    q = k==0 ? q0 : k==1 ? q1 : k==2 ? q2 : k==3 ? q3 : q4;
                    cv::meanStdDev(q, mean_m, stddev_m, cv::noArray());
                    mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                    if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                }

                *(p + y*cols+x) = best_mean;
            }
        }
        cv::cvtColor(result, bgrMat, CV_GRAY2BGR);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherFFT (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("FFT: ") + windowTitle[qHash(label)];
    calculerFFT(image, titre);
}

void MainWindow::calculerFFT (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::cvtColor(bgrMat, bgrMat, CV_BGR2GRAY);

    cv::Mat padded;                            //expand input image to optimal size
    int m = cv::getOptimalDFTSize( bgrMat.rows );
    int n = cv::getOptimalDFTSize( bgrMat.cols ); // on the border add zero values
    cv::copyMakeBorder(bgrMat, padded, 0, m - bgrMat.rows, 0, n - bgrMat.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

    cv::Mat planes[] = {cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F)};
    cv::Mat complexI;
    cv::merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

    cv::dft(complexI, complexI);            // this way the result may fit in the source matrix

    // compute the magnitude and switch to logarithmic scale
    // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
    cv::split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
    cv::magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
    cv::Mat magI = planes[0];

    magI += cv::Scalar::all(1);                    // switch to logarithmic scale
    cv::log(magI, magI);

    // crop the spectrum, if it has an odd number of rows or columns
    magI = magI(cv::Rect(0, 0, magI.cols & -2, magI.rows & -2));

    // rearrange the quadrants of Fourier image  so that the origin is at the image center
    int cx = magI.cols/2;
    int cy = magI.rows/2;

    cv::Mat q0(magI, cv::Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    cv::Mat q1(magI, cv::Rect(cx, 0, cx, cy));  // Top-Right
    cv::Mat q2(magI, cv::Rect(0, cy, cx, cy));  // Bottom-Left
    cv::Mat q3(magI, cv::Rect(cx, cy, cx, cy)); // Bottom-Right

    cv::Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);

    cv::normalize(magI, magI, 0, 1, CV_MINMAX); // Transform the matrix with float values into a
                                            // viewable image form (float between values 0 and 1).
    magI.convertTo (bgrMat, CV_8U, 255);
    cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);

    cvMatToQImage (bgrMat, argbImage);
    creerFenetre (QPixmap::fromImage (argbImage), titre);
}

//menu segmentation
void MainWindow::afficherSeuillageManuelSimple (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int seuil = QInputDialog::getInt(this, tr("Seuillage Simple"), tr("Seuil (entre 0 et 255): "), 127, 0, 255, 1, &ok, 0);
    if (!ok) return;
    statusBar()->showMessage(tr("Seuillage(%1): ").arg(seuil));
    QString titre = QString("Seuillage(%1): ").arg(seuil) + windowTitle[qHash(label)];
    calculerSeuillageManuelSimple (image, titre, seuil, SEUILLAGE_VALEUR_MAX);
}

void MainWindow::calculerSeuillageManuelSimple (QImage& argbImage, QString titre, double seuil, double maxval) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::threshold(bgrMat, bgrMat, seuil, maxval, cv::THRESH_BINARY);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherSeuillageVarianceSimple (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok = true;
    if (!ok) return;
    statusBar()->showMessage(tr("Seuillage Simple [Variance]: "));
    QString titre = QString("Seuillage Simple [Variance]: ") + windowTitle[qHash(label)];
    calculerSeuillageVarianceSimple (image, titre, 0, 255);
}

void MainWindow::calculerSeuillageVarianceSimple (QImage& argbImage, QString titre, double seuil, double maxval) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::cvtColor(bgrMat, bgrMat, CV_BGR2GRAY);
    cv::threshold(bgrMat, bgrMat, seuil, maxval, cv::THRESH_BINARY | cv::THRESH_OTSU);
    cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherSeuillageManuelDouble (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    int seuil1, seuil2;
    bool ok;
    IntIntDialog d(this, QString("Seuillage Double"), QString("Seuil Inférieur (entre 0 et 255): "), 84, 0, 255, 1, QString("Seuil Supérieur (entre 0 et 255): "), 252, 0, 255, 1);
    d.run(seuil1, seuil2, ok);
    if (!ok) return;
    statusBar()->showMessage(tr("Seuillage Double Manuel(%1;%2): ").arg(seuil1).arg(seuil2));
    QString titre = QString("Seuillage Double Manuel(%1;%2): ").arg(seuil1).arg(seuil2) + windowTitle[qHash(label)];
    image = calculerSeuillageManuelDouble(image, seuil1, seuil2, 0, SEUILLAGE_VALEUR_MIL, SEUILLAGE_VALEUR_MAX);
    creerFenetre(QPixmap::fromImage(image), titre);
}

const QImage& MainWindow::calculerSeuillageManuelDouble (const QImage& argbImage, double seuilBas, double seuilHaut, double minVal, double midVal, double maxVal) {
    static cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::MatIterator_<cv::Vec3b> it, end;
    for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
        (*it)[0] = (*it)[0] < seuilBas ? minVal : (*it)[0] > seuilHaut ? maxVal : midVal;
        (*it)[1] = (*it)[1] < seuilBas ? minVal : (*it)[1] > seuilHaut ? maxVal : midVal;
        (*it)[2] = (*it)[2] < seuilBas ? minVal : (*it)[2] > seuilHaut ? maxVal : midVal;
    }

    static QImage result;
    cvMatToQImage(bgrMat, result);
    return result;
}

void MainWindow::afficherSeuillageVarianceDouble (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    int seuil1, seuil2;
    bool ok;
    IntIntDialog d(this, QString("Seuillage Double [Variance]"), QString("Seuil Inférieur (entre 0 et 255): "), 84, 0, 255, 1, QString("Seuil Supérieur (entre 0 et 255): "), 252, 0, 255, 1);
    d.run(seuil1, seuil2, ok);
    if (!ok) return;
    statusBar()->showMessage(tr("Seuillage Double [Variance](%1;%2): ").arg(seuil1).arg(seuil2));
    QString titre = QString("Seuillage Double [Variance](%1;%2): ").arg(seuil1).arg(seuil2) + windowTitle[qHash(label)];
    calculerSeuillageVarianceDouble (image, titre, seuil1, seuil2, 0, SEUILLAGE_VALEUR_MIL, SEUILLAGE_VALEUR_MAX);
}

void MainWindow::calculerSeuillageVarianceDouble (QImage& argbImage, QString titre, double seuilBas, double seuilHaut, double minVal, double midVal, double maxVal) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::cvtColor(bgrMat, bgrMat, CV_BGR2GRAY);
    cv::Mat data, labels(256, 1, CV_32SC1);
    bgrMat.convertTo(data, CV_32F, 1.f, 0);
    int* labelsTable = (int*)labels.data;
    for(int i = 0; i < seuilBas; i++)
        labelsTable[i] = 0;
    for(int i = seuilBas; i < seuilHaut; i++)
        labelsTable[i] = 1;
    for(int i = seuilHaut; i < 256; i++)
        labelsTable[i] = 2;
    cv::TermCriteria criteria;
    criteria.epsilon = 0.000001;
    cv::kmeans(data, 3, labels, criteria, 100, cv::KMEANS_USE_INITIAL_LABELS, cv::noArray());
    int rows = bgrMat.rows;
    int cols = bgrMat.cols;
    cols *= rows;
    uchar c, v; uchar* p = (uchar*)bgrMat.data;
    for (int i = 0; i < cols; i++) {
        c = labelsTable[p[i]];
        v = c == 0 ? minVal : c == 1 ? midVal : maxVal;
        p[i] = v;
    }
    cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherSeuillageParHysteresis (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    int seuil1, seuil2;
    bool ok;
    IntIntDialog d(this, QString("Seuillage par Hystérésis"), QString("Seuil Inférieur (entre 0 et 255): "), 84, 0, 255, 1, QString("Seuil Supérieur (entre 0 et 255): "), 252, 0, 255, 1);
    d.run(seuil1, seuil2, ok);
    if (!ok) return;
    statusBar()->showMessage(tr("Seuillage par Hystérésis(%1;%2): ").arg(seuil1).arg(seuil2));
    QString titre = QString("Seuillage par Hystérésis(%1;%2): ").arg(seuil1).arg(seuil2) + windowTitle[qHash(label)];
    calculerSeuillageParHysteresis (image, titre, seuil1, seuil2);///ratio seuilHaut/seuilBas preferablement entre 3:1 et 2:1
}

void MainWindow::calculerSeuillageParHysteresis (QImage& argbImage, QString titre, int seuilBas, int seuilHaut) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    uchar minVal = 0, midVal = SEUILLAGE_VALEUR_MIL, maxVal = SEUILLAGE_VALEUR_MAX;
    //QImageTocvMat(argbImage, bgrMat);
    cv::cvtColor(bgrMat, bgrMat, CV_BGR2GRAY);
    uchar v; cv::MatIterator_<uchar> it, end;
    for(it = bgrMat.begin<uchar>(), end = bgrMat.end<uchar>(); it != end; ++it) {
        v = *it;
        *it = v < seuilBas ? minVal : v > seuilHaut ? maxVal : midVal;
    }
    cv::Mat validationfw = bgrMat.clone();
    cv::Mat validationbw = bgrMat.clone();
    int rows = bgrMat.rows;
    int cols = bgrMat.cols;cv::imshow("pre", bgrMat);
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            traiterPixelHysteresisfw (bgrMat, validationfw, x, y, cols, rows);
        }
    }cv::imshow("fw", bgrMat);
    for (int y = rows-1; y > -1; y--) {
        for (int x = cols-1; x > -1; x--) {
            traiterPixelHysteresisbw (bgrMat, validationbw, x, y, cols, rows);
        }
    }cv::imshow("bw", bgrMat);
    cv::threshold(bgrMat, bgrMat, midVal+1, maxVal, cv::THRESH_BINARY);cv::imshow("thresh", bgrMat);
    cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::traiterPixelHysteresisfw (cv::Mat& bgrMat, cv::Mat& validation, int x, int y, int cols, int rows) {
    uchar v; uchar* p = (uchar*) validation.data;
    if (x > cols-1 || y > rows-1 || x < 0 || y < 0) return;
    v = p[y*cols+x];
    if(v == 0) return;
    if (x > 0) {
        if (x < cols-1) {
            if (y < rows-1) {
                cv::Mat voisinage (bgrMat, cv::Rect(x-1, y, 3, 2));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(0, 2) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 2) = 255;
                    if(voisinage.at<uchar>(1, 2) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(1, 2) = 255;
                    if(voisinage.at<uchar>(1, 1) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(1, 1) = 255;
                    if(voisinage.at<uchar>(1, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(1, 0) = 255;
                }
                traiterPixelHysteresisfw (bgrMat, validation, x+1, y, cols, rows);
                traiterPixelHysteresisfw (bgrMat, validation, x+1, y+1, cols, rows);
                traiterPixelHysteresisfw (bgrMat, validation, x, y+1, cols, rows);
                traiterPixelHysteresisfw (bgrMat, validation, x-1, y+1, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(0, 2) == 255 || voisinage.at<uchar>(1, 2) == 255 || voisinage.at<uchar>(1, 1) == 255 || voisinage.at<uchar>(1, 0) == 255)
                        voisinage.at<uchar>(0, 1) = 255;
                }
            } else {
                cv::Mat voisinage (bgrMat, cv::Rect(x, y, 2, 1));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(0, 1) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 1) = 255;
                }
                traiterPixelHysteresisfw (bgrMat, validation, x+1, y, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(0, 1) == 255)
                        voisinage.at<uchar>(0, 0) = 255;
                }
            }
        } else {
            if (y < rows-1) {
                cv::Mat voisinage (bgrMat, cv::Rect(x-1, y, 2, 2));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(1, 1) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(1, 1) = 255;
                    if(voisinage.at<uchar>(1, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(1, 0) = 255;
                }
                traiterPixelHysteresisfw (bgrMat, validation, x, y+1, cols, rows);
                traiterPixelHysteresisfw (bgrMat, validation, x-1, y+1, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(1, 1) == 255 || voisinage.at<uchar>(1, 0) == 255)
                        voisinage.at<uchar>(0, 1) = 255;
                }
            } else {
                //rien;
            }
        }
    } else {
        if (x < cols-1) {
            if (y < rows-1) {
                cv::Mat voisinage (bgrMat, cv::Rect(x, y, 2, 2));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(0, 1) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 1) = 255;
                    if(voisinage.at<uchar>(1, 1) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(1, 1) = 255;
                    if(voisinage.at<uchar>(1, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(1, 0) = 255;
                }
                traiterPixelHysteresisfw (bgrMat, validation, x+1, y, cols, rows);
                traiterPixelHysteresisfw (bgrMat, validation, x+1, y+1, cols, rows);
                traiterPixelHysteresisfw (bgrMat, validation, x, y+1, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(0, 1) == 255 || voisinage.at<uchar>(1, 1) == 255 || voisinage.at<uchar>(1, 0) == 255)
                        voisinage.at<uchar>(0, 0) = 255;
                }
            } else {
                cv::Mat voisinage (bgrMat, cv::Rect(x, y, 2, 1));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(0, 1) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 1) = 255;
                }
                traiterPixelHysteresisfw (bgrMat, validation, x+1, y, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(0, 1) == 255)
                        voisinage.at<uchar>(0, 0) = 255;
                }
            }
        } else {
            if (y < rows-1) {
                cv::Mat voisinage (bgrMat, cv::Rect(x, y, 1, 2));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(1, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(1, 0) = 255;
                }
                traiterPixelHysteresisfw (bgrMat, validation, x, y+1, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(1, 0) == 255)
                        voisinage.at<uchar>(0, 0) = 255;
                }
            } else {
                //rien;
            }
        }
    }
    p[y*cols+x] = 0;
}

void MainWindow::traiterPixelHysteresisbw (cv::Mat& bgrMat, cv::Mat& validation, int x, int y, int cols, int rows) {
    uchar v; uchar* p = (uchar*) validation.data;
    if (x < 0 || y < 0 || x > cols-1 || y > rows-1) return;
    v = p[y*cols+x];
    if(v == 0) return;
    if (x < cols-1) {
        if (x > 0) {
            if (y > 0) {
                cv::Mat voisinage (bgrMat, cv::Rect(x-1, y-1, 3, 2));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(1, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(1, 0) = 255;
                    if(voisinage.at<uchar>(0, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 0) = 255;
                    if(voisinage.at<uchar>(0, 1) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 1) = 255;
                    if(voisinage.at<uchar>(0, 2) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 2) = 255;
                }
                traiterPixelHysteresisbw (bgrMat, validation, x-1, y, cols, rows);
                traiterPixelHysteresisbw (bgrMat, validation, x-1, y-1, cols, rows);
                traiterPixelHysteresisbw (bgrMat, validation, x, y-1, cols, rows);
                traiterPixelHysteresisbw (bgrMat, validation, x+1, y-1, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(1, 0) == 255 || voisinage.at<uchar>(0, 0) == 255 || voisinage.at<uchar>(0, 1) == 255 || voisinage.at<uchar>(0, 2))
                        voisinage.at<uchar>(1, 1) = 255;
                }
            } else {
                cv::Mat voisinage (bgrMat, cv::Rect(x-1, y, 2, 1));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(0, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 0) = 255;
                }
                traiterPixelHysteresisbw (bgrMat, validation, x-1, y, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(0, 0) == 255)
                        voisinage.at<uchar>(0, 1) = 255;
                }
            }
        } else {
            if (y > 0) {
                cv::Mat voisinage (bgrMat, cv::Rect(x, y-1, 1, 2));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(0, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 0) = 255;
                    if(voisinage.at<uchar>(0, 1) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 1) = 255;
                }
                traiterPixelHysteresisbw (bgrMat, validation, x, y-1, cols, rows);
                traiterPixelHysteresisbw (bgrMat, validation, x+1, y-1, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(0, 0) == 255 || voisinage.at<uchar>(0, 1) == 255)
                        voisinage.at<uchar>(1, 0) = 255;
                }
            } else {
                //rien;
            }
        }
    } else {
        if (x > 0) {
            if (y > 0) {
                cv::Mat voisinage (bgrMat, cv::Rect(x-1, y-1, 2, 2));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(1, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(1, 0) = 255;
                    if(voisinage.at<uchar>(0, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 0) = 255;
                    if(voisinage.at<uchar>(0, 1) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 1) = 255;
                }
                traiterPixelHysteresisbw (bgrMat, validation, x-1, y, cols, rows);
                traiterPixelHysteresisbw (bgrMat, validation, x-1, y-1, cols, rows);
                traiterPixelHysteresisbw (bgrMat, validation, x, y-1, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(1, 0) == 255 || voisinage.at<uchar>(0, 0) == 255 || voisinage.at<uchar>(0, 1) == 255)
                        voisinage.at<uchar>(1, 1) = 255;
                }
            } else {
                cv::Mat voisinage (bgrMat, cv::Rect(x-1, y, 2, 1));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(0, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 0) = 255;
                }
                traiterPixelHysteresisbw (bgrMat, validation, x-1, y, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(0, 0) == 255)
                        voisinage.at<uchar>(0, 1) = 255;
                }
            }
        } else {
            if (y > 0) {
                cv::Mat voisinage (bgrMat, cv::Rect(x, y-1, 1, 2));
                if(v == SEUILLAGE_VALEUR_MAX) {
                    if(voisinage.at<uchar>(0, 0) == SEUILLAGE_VALEUR_MIL) voisinage.at<uchar>(0, 0) = 255;
                }
                traiterPixelHysteresisbw (bgrMat, validation, x, y-1, cols, rows);
                if(v == SEUILLAGE_VALEUR_MIL) {
                    if(voisinage.at<uchar>(0, 0) == 255)
                        voisinage.at<uchar>(1, 0) = 255;
                }
            } else {
                //rien;
            }
        }
    }
    p[y*cols+x] = 0;
}

void MainWindow::afficherBiseuillage (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    int seuil1, seuil2;
    bool ok;
    IntIntDialog d(this, QString("Biseuillage"), QString("Seuil Inférieur (entre 0 et 255): "), 84, 0, 255, 1, QString("Seuil Supérieur (entre 0 et 255): "), 252, 0, 255, 1);
    d.run(seuil1, seuil2, ok);
    if (!ok) return;
    statusBar()->showMessage(tr("Biseuillage(%1;%2): ").arg(seuil1).arg(seuil2));
    QString titre = QString("Biseuillage(%1;%2): ").arg(seuil1).arg(seuil2) + windowTitle[qHash(label)];
    calculerBiseuillage (image, titre, seuil1, seuil2);
}

void MainWindow::calculerBiseuillage (QImage& argbImage, QString titre, int seuilBas, int seuilHaut) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::cvtColor(bgrMat, bgrMat, CV_BGR2GRAY);

    uchar minVal = 0, midVal = SEUILLAGE_VALEUR_MIL, maxVal = SEUILLAGE_VALEUR_MAX;
    uchar v; cv::MatIterator_<uchar> it, end;
    for(it = bgrMat.begin<uchar>(), end = bgrMat.end<uchar>(); it != end; ++it) {
        v = *it;
        *it = v < seuilBas ? minVal : v > seuilHaut ? maxVal : midVal;
    }

    cv::Mat validationBlanc, validationNoir;
    cv::threshold(bgrMat, validationBlanc, midVal, maxVal, cv::THRESH_BINARY_INV);
    cv::threshold(bgrMat, validationNoir, midVal-1, maxVal, cv::THRESH_BINARY);

    cv::Mat distanceBlanc, distanceNoir;
    cv::distanceTransform(validationBlanc, distanceBlanc, CV_DIST_L2, 3);
    cv::distanceTransform(validationNoir, distanceNoir, CV_DIST_L2, 3);

    int rows = bgrMat.rows;
    int cols = bgrMat.cols * rows;
    uchar* p = (uchar*)bgrMat.data;
    float* d1 = (float*)distanceBlanc.data,* d2 = (float*)distanceNoir.data;
    for (int i = 0; i < cols; i++) {
        if(p[i] == midVal)
            p[i] = d1[i] < d2 [i] ? maxVal : minVal;
    }

    cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherGradientSobel (QLabel* label, TypeSobel type) {
    QImage image = label->pixmap()->toImage();
    double gain;
    int offset;
    bool ok;
    DoubleIntDialog d(this, QString("Gradient Sobel"), QString("Gain (entre 1 et 30): "), 1, 1, 30, 2, QString("Offset (entre 0 et 255): "), 0, 0, 255, 1);
    d.run(gain, offset, ok);
    if (!ok) return;
    statusBar()->showMessage(tr("Gradient Sobel %1(%2;%3): ").arg(type == SOBEL_NORME ? "[Norme]" : type == SOBEL_X ? "X" : type == SOBEL_Y ? "Y" : "").arg(gain).arg(offset));
    QString titre = QString("Gradient Sobel %1(%2;%3): ").arg(type == SOBEL_NORME ? "[Norme]" : type == SOBEL_X ? "X" : type == SOBEL_Y ? "Y" : "").arg(gain).arg(offset) + windowTitle[qHash(label)];
    calculerGradientSobel (image, titre, type, 3, gain, offset, BORDER_TYPE);
}

void MainWindow::calculerGradientSobel (QImage& argbImage, QString titre, TypeSobel type, int ksize, double gain, double offset, int borderType) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    int dx, dy;
    if (type == SOBEL_X || type == SOBEL_Y) {
        if (type == SOBEL_X) {
            dx = 1;
            dy = 0;
        } else {
            dx = 0;
            dy = 1;
        }
        cv::GaussianBlur(bgrMat, bgrMat, cv::Size(3,3), 0, 0, borderType);
        cv::Mat gMat;
        cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
        cv::Mat dst;
        cv::Sobel (gMat, dst, CV_16S, dx, dy, ksize, gain, offset, borderType);
        cv::convertScaleAbs(dst, bgrMat);
        cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);
    } else if (type == SOBEL_NORME) {
        cv::GaussianBlur(bgrMat, bgrMat, cv::Size(3,3), 0, 0, borderType);
        cv::Mat gMat;
        cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
        cv::Mat dst_x, dst_y, dst_total;
        cv::Mat x, y, s;
        ///d/dx
        dx = 1;
        dy = 0;
        cv::Sobel (gMat, dst_x, CV_16S, dx, dy, ksize, gain, offset, borderType);
        dst_x.convertTo(x, CV_32F, 1.f, 0);
        ///d/dy
        dx = 0;
        dy = 1;
        cv::Sobel (gMat, dst_y, CV_16S, dx, dy, ksize, gain, offset, borderType);
        dst_y.convertTo(y, CV_32F, 1.f, 0);
        cv::magnitude(x, y, dst_total);
        cv::normalize(dst_total, dst_total, 0, 1, CV_MINMAX);
        dst_total.convertTo(dst_total, CV_8U, 255, 0);
        cv::cvtColor(dst_total, bgrMat, CV_GRAY2BGR);
    }
    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherGradientPrewitt (QLabel* label, TypePrewitt type) {
    QImage image = label->pixmap()->toImage();
    double gain;
    int offset;
    bool ok;
    DoubleIntDialog d(this, QString("Gradient Prewitt"), QString("Gain (entre 1 et 30): "), 1, 1, 30, 2, QString("Offset (entre 0 et 255): "), 0, 0, 255, 1);
    d.run(gain, offset, ok);
    if (!ok) return;
    statusBar()->showMessage(tr("Gradient Prewitt %1(%2;%3): ").arg(type == PREWITT_NORME ? "[Norme]" : type == PREWITT_X ? "X" : type == PREWITT_Y ? "Y" : "").arg(gain).arg(offset));
    QString titre = QString("Gradient Prewitt %1(%2;%3): ").arg(type == PREWITT_NORME ? "[Norme]" : type == PREWITT_X ? "X" : type == PREWITT_Y ? "Y" : "").arg(gain).arg(offset) + windowTitle[qHash(label)];
    calculerGradientPrewitt (image, titre, type, gain, offset, BORDER_TYPE);
}

void MainWindow::calculerGradientPrewitt (QImage& argbImage, QString titre, TypePrewitt type, double gain, double offset, int borderType) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    int dx, dy;
    if (type == PREWITT_X || type == PREWITT_Y) {
        if (type == PREWITT_X) {
            dx = 1;
            dy = 0;
        } else {
            dx = 0;
            dy = 1;
        }
        cv::GaussianBlur(bgrMat, bgrMat, cv::Size(3,3), 0, 0, borderType);
        cv::Mat gMat;
        cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
        cv::Mat dst;
        Prewitt(gMat, dst, CV_16S, dx, dy, gain*25, offset, borderType);
        cv::convertScaleAbs(dst, bgrMat);
        cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);
    } else if (type == PREWITT_NORME) {
        cv::GaussianBlur(bgrMat, bgrMat, cv::Size(3,3), 0, 0, borderType);
        cv::Mat gMat;
        cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
        cv::Mat dst_x, dst_y, dst_total;
        cv::Mat x, y, s;
        ///d/dx
        dx = 1;
        dy = 0;
        Prewitt(gMat, dst_x, CV_16S, dx, dy, gain, offset, borderType);
        dst_x.convertTo(x, CV_32F, 1.f, 0);
        ///d/dy
        dx = 0;
        dy = 1;
        Prewitt(gMat, dst_y, CV_16S, dx, dy, gain, offset, borderType);
        dst_y.convertTo(y, CV_32F, 1.f, 0);
        cv::magnitude(x, y, dst_total);
        cv::normalize(dst_total, dst_total, 0, 1, CV_MINMAX);
        dst_total.convertTo(dst_total, CV_8U, 255, 0);
        cv::cvtColor(dst_total, bgrMat, CV_GRAY2BGR);
    }
    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}



///
///
///   SLOTS
///
///



//menu fichier
void MainWindow::on_actionOuvrir_triggered () {
    QFileDialog fileDialog;
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    QString nomFichier = fileDialog.getOpenFileName(this, tr("Ouvrir Image"), tr(DOSSIER_DEFAUT_OUVERTURE_IMAGES), tr(PATTERN_OUVERTURE_IMAGES_QT_ET_OPENCV));
    if (nomFichier.isEmpty())
        return;
    ouvrirImage(nomFichier.toStdString().data());
}

void MainWindow::on_actionFermerTout_triggered () {
    if (getFocusedArea() == NULL && getFirstUnfocusedArea() == NULL)
        return;
    fermerTout();
}

//menu affichage
void MainWindow::on_actionTailleNormale_triggered () {
    QScrollArea* scrollArea = getFocusedArea();
    if (scrollArea == NULL)
        return;
    scaleImage(scrollArea, 1/scaleFactor[qHash(getLabelInArea(scrollArea))]);
}


void MainWindow::on_actionZoomIn_triggered () {
    QScrollArea* scrollArea = getFocusedArea();
    if (scrollArea == NULL)
        return;
    scaleImage(scrollArea, 1.25);
}

void MainWindow::on_actionZoomOut_triggered () {
    QScrollArea* scrollArea = getFocusedArea();
    if (scrollArea == NULL)
        return;
    scaleImage(scrollArea, 0.80);
}

void MainWindow::on_actionCvtColorInverse_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherPalette(label, CVT_COLOR_INVERSE);
}

void MainWindow::on_actionThermal_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherPalette(label, THERMAL);
}

void MainWindow::on_actionCvtColor_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherPalette(label, CVT_COLOR);
}

void MainWindow::on_actionMRI_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherPalette(label, MRI);
}

void MainWindow::on_actionColdToHot_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherPalette(label, COLD_TO_HOT);
}

void MainWindow::on_actionJet_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherPalette(label, JET);
}

void MainWindow::on_actionDupliquer_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    dupliquer(label);
}

//menu outils
void MainWindow::on_actionAffichage_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherHistogramme (label);
}

void MainWindow::on_actionRecadrage_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherRecadrage(label);
}

void MainWindow::on_actionNegatif_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherHistogrammeNegatif (label);
}

void MainWindow::on_actionCalibration_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherCalibration (label);
}

void MainWindow::on_actionEgalisation_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherEgalisation (label);
}

void MainWindow::on_actionLogarithmique_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherLogarithmique (label);
}

void MainWindow::on_actionExponentielle_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherExponentielle (label);
}

void MainWindow::on_actionAddition_triggered () {
    QLabel* labelGauche = getFocusedLabel();
    if (labelGauche == NULL)
        return;
    QLabel* labelDroite = getFirstUnfocusedLabel();
    if (labelDroite == NULL)
        return;
    afficherAddition (labelGauche, labelDroite);
}

void MainWindow::on_actionSoustraction_triggered () {
    QLabel* labelGauche = getFocusedLabel();
    if (labelGauche == NULL)
        return;
    QLabel* labelDroite = getFirstUnfocusedLabel();
    if (labelDroite == NULL)
        return;
    afficherSoustraction (labelGauche, labelDroite);
}

void MainWindow::on_actionCombinaison_triggered () {
    QLabel* labelGauche = getFocusedLabel();
    if (labelGauche == NULL)
        return;
    QLabel* labelDroite = getFirstUnfocusedLabel();
    if (labelDroite == NULL)
        return;
    afficherCombinaison (labelGauche, labelDroite);
}

void MainWindow::on_actionMinimum_triggered () {
    QLabel* labelGauche = getFocusedLabel();
    if (labelGauche == NULL)
        return;
    QLabel* labelDroite = getFirstUnfocusedLabel();
    if (labelDroite == NULL)
        return;
    afficherMinimum (labelGauche, labelDroite);
}

void MainWindow::on_actionMaximum_triggered () {
    QLabel* labelGauche = getFocusedLabel();
    if (labelGauche == NULL)
        return;
    QLabel* labelDroite = getFirstUnfocusedLabel();
    if (labelDroite == NULL)
        return;
    afficherMaximum (labelGauche, labelDroite);
}

void MainWindow::on_actionAND_triggered () {
    QLabel* labelGauche = getFocusedLabel();
    if (labelGauche == NULL)
        return;
    QLabel* labelDroite = getFirstUnfocusedLabel();
    if (labelDroite == NULL)
        return;
    afficherAND (labelGauche, labelDroite);
}

void MainWindow::on_actionOR_triggered () {
    QLabel* labelGauche = getFocusedLabel();
    if (labelGauche == NULL)
        return;
    QLabel* labelDroite = getFirstUnfocusedLabel();
    if (labelDroite == NULL)
        return;
    afficherOR (labelGauche, labelDroite);
}

void MainWindow::on_actionXOR_triggered () {
    QLabel* labelGauche = getFocusedLabel();
    if (labelGauche == NULL)
        return;
    QLabel* labelDroite = getFirstUnfocusedLabel();
    if (labelDroite == NULL)
        return;
    afficherXOR (labelGauche, labelDroite);
}

void MainWindow::on_actionNOT_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherNOT (label);
}

void MainWindow::on_actionPlanBinaire_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherPlanBinaire (label);
}

void MainWindow::on_actionQuantification_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherQuantification (label);
}

void MainWindow::on_actionChangementDEchelle_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherChangementDEchelle (label);
}

void MainWindow::on_actionRotation_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherRotation (label);
}

void MainWindow::on_actionRotationInterpolee_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherRotationInterpolee (label);
}

void MainWindow::on_actionTransposee_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherTransposee (label);
}

void MainWindow::on_actionVuePerspective_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherVuePerspective (label);
}

void MainWindow::on_actionBruitUniforme_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherBruitUniforme (label);
}

void MainWindow::on_actionBruitPoivreEtSel_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherBruitPoivreEtSel (label);
}

void MainWindow::on_actionUniforme_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        afficherUniforme ();
    else
        afficherUniforme (label);
}

void MainWindow::on_actionRampe_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        afficherRampe ();
    else
        afficherRampe (label);
}
//menu filtrage
void MainWindow::on_actionMoyenneur3x3_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherMoyenneur3x3 (label);
}

void MainWindow::on_actionMoyenneurNxN_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherMoyenneurNxN (label);
}

void MainWindow::on_actionLaplacien_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherLaplacien (label);
}

void MainWindow::on_actionMedian_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherMedian (label);
}

void MainWindow::on_actionVFiltre_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherVFiltre (label);
}

void MainWindow::on_actionFFT_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherFFT (label);
}

//menu segmentation
void MainWindow::on_actionManuelSimple_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherSeuillageManuelSimple (label);
}

void MainWindow::on_actionVarianceSimple_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherSeuillageVarianceSimple (label);
}

void MainWindow::on_actionManuelDouble_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherSeuillageManuelDouble (label);
}

void MainWindow::on_actionVarianceDouble_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherSeuillageVarianceDouble (label);
}

void MainWindow::on_actionSeuillageParHysteresis_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherSeuillageParHysteresis (label);
}

void MainWindow::on_actionBiseuillage_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherBiseuillage (label);
}

void MainWindow::on_actionNormeSobel_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherGradientSobel (label, SOBEL_NORME);
}

void MainWindow::on_actionGradientXSobel_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherGradientSobel (label, SOBEL_X);
}

void MainWindow::on_actionGradientYSobel_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherGradientSobel (label, SOBEL_Y);
}

void MainWindow::on_actionNormePrewitt_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherGradientPrewitt (label, PREWITT_NORME);
}

void MainWindow::on_actionGradientXPrewitt_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherGradientPrewitt (label, PREWITT_X);
}

void MainWindow::on_actionGradientYPrewitt_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherGradientPrewitt (label, PREWITT_Y);
}

