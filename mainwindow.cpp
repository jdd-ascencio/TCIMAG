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

/*
//void cv::Scharr(InputArray _src, OutputArray _dst, int ddepth, int dx, int dy, double scale, double delta, int borderType)
    / *
    Mat src = _src.getMat();
    if (ddepth < 0)
        ddepth = src.depth();
    _dst.create( src.size(), CV_MAKETYPE(ddepth, src.channels()) );
    Mat dst = _dst.getMat();
    * /
    cv::Mat src = ((cv::InputArray)gMat).getMat();
    if (ddepth < 0)
        ddepth = src.depth();
    ((cv::OutputArray)_dst).create(src.size(), CV_MAKETYPE(ddepth, src.channels()));
    cv::Mat dst = ((cv::OutputArray)_dst).getMat();

    int ktype = std::max(CV_32F, std::max(ddepth, src.depth()));

    cv::Mat kx, ky;
    //getScharrKernels(_kx, _ky, dx, dy, false, ktype);
    //static void getScharrKernels(OutputArray _kx, OutputArray _ky, int dx, int dy, bool normalize, int ktype) {
    //const int ksize = 3;

    CV_Assert(ktype == CV_32F || ktype == CV_64F);
    ((cv::OutputArray)kx).create(ksize, 1, ktype, -1, true);
    ((cv::OutputArray)ky).create(ksize, 1, ktype, -1, true);
    cv::Mat _kx = ((cv::InputArray)kx).getMat();
    cv::Mat _ky = ((cv::InputArray)ky).getMat();

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
        double scale = !true || order == 1 ? 1. : 1./32;
        temp.convertTo(*kernel, ktype, scale);
    }
    //}
    if(gain != 1) {
        // usually the smoothing part is the slowest to compute,
        // so try to scale it instead of the faster differenciating part
        if(dx == 0)
            kx *= gain;
        else
            ky *= gain;
    }
    cv::sepFilter2D(src, dst, ddepth, kx, ky, cv::Point(-1,-1), offset, borderType);
*/


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

MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent), ui (new Ui::MainWindow) {
    ui->setupUi(this);
    rng = cv::RNG(cv::getTickCount());

    //ouvrirImage("../TCIMAG_ressources/lena.bmp");
    //ouvrirImage("../TCIMAG_ressources/lenaGray.bmp");
    //ouvrirImage("../TCIMAG_ressources/lena.jpg");
    //ouvrirImage("../TCIMAG_ressources/lena.jpeg");
    //ouvrirImage("../TCIMAG_ressources/lena.png");
    //ouvrirImage("../TCIMAG_ressources/lena.pgm");
    //ouvrirImage("../TCIMAG_ressources/lena.ppm");
    //ouvrirImage("../TCIMAG_ressources/lena.tiff");

    //ouvrirImage("../TCIMAG_ressources/QUITO.PNG");
    ouvrirImage("../TCIMAG_ressources/RONDELLE.PNG");
    ouvrirImage("../TCIMAG_ressources/SPOT.PNG");

    //PARTIE 1
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

    //PARTIE 2
    //ouvrirImage("../TCIMAG_ressources/ANGIO.PNG");
    //ouvrirImage("../TCIMAG_ressources/BOUGIES.PNG");
    //ouvrirImage("../TCIMAG_ressources/LENA.PNG");
    //ouvrirImage("../TCIMAG_ressources/MUSCLE.PNG");
    //ouvrirImage("../TCIMAG_ressources/QUITO.PNG");
    //ouvrirImage("../TCIMAG_ressources/RONDELLE.PNG");

    //PARTIE 3
    //ouvrirImage("../TCIMAG_ressources/AMOUR.PNG");
    //ouvrirImage("../TCIMAG_ressources/BRUIT.PNG");
    //ouvrirImage("../TCIMAG_ressources/FILM.PNG");
    //ouvrirImage("../TCIMAG_ressources/FISSURE.PNG");
    //ouvrirImage("../TCIMAG_ressources/MEB.PNG");
    //ouvrirImage("../TCIMAG_ressources/MORPHO.PNG");
    //ouvrirImage("../TCIMAG_ressources/OBJETS.PNG");
    //ouvrirImage("../TCIMAG_ressources/RONDELLE.PNG");
    //ouvrirImage("../TCIMAG_ressources/SPOT.PNG");

    //menu outils
    ui->actionAffichage->setEnabled(true);
    ui->actionRecadrage->setEnabled(true);
    ui->actionNegatif->setEnabled(true);
    ui->actionAddition->setEnabled(true);
    ui->actionCalibration->setEnabled(true);//ui->actionGainOffsetHistogramme->setEnabled(true);
    ui->actionEgalisation->setEnabled(true);
    ui->actionExponentielle->setEnabled(true);
    ui->actionLogarithmique->setEnabled(true);
    ui->actionSoustraction->setEnabled(true);
    ui->actionCombinaison->setEnabled(true);
    ui->actionMinimum->setEnabled(true);
    ui->actionMaximum->setEnabled(true);
    ui->actionAND->setEnabled(true);
    ui->actionOR->setEnabled(true);
    ui->actionXOR->setEnabled(true);
    ui->actionNOT->setEnabled(true);
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
    ui->actionManuelDouble->setEnabled(true);
    ui->actionSeuillageParHysteresis->setEnabled(true);
    ui->actionNormeSobel->setEnabled(true);
    ui->actionGradientXSobel->setEnabled(true);
    ui->actionGradientYSobel->setEnabled(true);
    ui->actionNormePrewitt->setEnabled(true);
    ui->actionGradientXPrewitt->setEnabled(true);
    ui->actionGradientYPrewitt->setEnabled(true);
}

MainWindow::~MainWindow () {
    delete ui;
}

///
///
///   fonctions
///
///

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
        //utiliser une police a largeur constante?
        QString message = QString ("[X,Y]=[Alpha,Red,Green,Blue]Gray   |   [%1,%2]=[%3,%4,%5,%6]%7")
                .arg (QString::number (x), 3).arg (QString::number (y), 3)
                .arg (QString::number (qAlpha (rgb)), 3)
                .arg (QString::number (qRed (rgb)), 3).arg (QString::number (qGreen (rgb)), 3).arg (QString::number (qBlue (rgb)), 3)
                .arg (QString::number (qGray (rgb)));
        this->statusBar()->showMessage(message);
    } else if (e->type() == QEvent::FocusIn) {
        //// QScrollableArea
        updateZoomActions (getLabelInArea ((QScrollArea*) watched));
    //} else if (e->type() == QEvent::WindowDeactivate) {
    //    std::cerr << "win deact: " << typeid(*watched).name() << std::endl;
    //} else if (e->type() == QEvent::Destroy) {
    //    std::cerr << std::endl << "destroyed: " << typeid(*watched).name() << std::endl ;
    } else if (e->type() == QEvent::Close) {
        if (typeid(*watched) == typeid(QScrollArea)) {
            //std::cerr << "closed: " << typeid(*watched).name() << std::endl;
            getLabelInArea((QScrollArea*) watched)->deleteLater();
            watched->deleteLater();
            watched->parent()->deleteLater();
        }
    }
    return QWidget::eventFilter(watched, e);
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

const QPixmap MainWindow::imageToQPixmap (const char* nomFichier) {
    cv::Mat loadImg;
    loadImg = cv::imread(nomFichier, CV_LOAD_IMAGE_COLOR);
    if (!loadImg.data) {
        std::cerr << "echec chargement image depuis fichier: " << nomFichier << std::endl;
        return QPixmap();
    }
    QImage rgbImg;
    cvMatToQImage(loadImg, rgbImg);
    return QPixmap::fromImage(rgbImg);
}

void MainWindow::ouvrirImage (const char* nomFichier) {
    QImage loadImg (nomFichier);
    if (loadImg.isNull()) {
        std::cerr << "echec chargement image depuis fichier: " << nomFichier << std::endl;
        return;
    }

    ////OpenCV charge l'image
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).absolutePath()); /// /home.../TCIMAG_ressources/lena.bmp
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).canonicalPath());/// /home.../TCIMAG_ressources/lena.bmp
    creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).dirName());        /// lena.bmp
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).homePath());     /// ~/
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).path());         /// ../TCIMAG_ressources/lena.bmp
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).rootPath());     /// /
    //creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).tempPath());     /// /tmp

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

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(labelImage);
    scrollArea->installEventFilter(this);

    QMdiSubWindow* subWindow = new QMdiSubWindow();
    subWindow->setParent(this->centralWidget());
    subWindow->setWindowTitle(titre);
    subWindow->setMinimumSize ((int)(pixmap.width () / 5), (int)(pixmap.height () / 5));
    subWindow->setWidget(scrollArea);
    subWindow->show();
}

void MainWindow::scaleImage (QScrollArea* scrollArea, double facteur) {
    QLabel* image = this->getLabelInArea(scrollArea);
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
    if (!this->scaleFactor.contains(qHash(image)))
        return;
    double scaleFactor = this->scaleFactor[qHash(image)];
    ui->actionZoomIn->setEnabled(scaleFactor < 3.0);
    ui->actionZoomOut->setEnabled(scaleFactor > 0.333);
}

QScrollArea* MainWindow::getFocusedArea() {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QList<QObject*> children = ui->centralWidget->children();
    if (children.isEmpty())
        return NULL;
    QObject* child = findFirstChildClassOf<QWidget>(children);
    if (child == NULL)
        return NULL;
    children = child->children();
    if (children.isEmpty())
        return NULL;
    QScrollArea* scrollArea;
    for (int i = 0; i < children.size(); i++) {
        child = findFirstChildClassOf<QScrollArea>(children.at(i)->children());
        if (child == NULL)
            continue;
        scrollArea = (QScrollArea*) child;
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
    QObject* child = findFirstChildClassOf<QWidget>(children);
    if (child == NULL)
        return NULL;
    children = child->children();
    if (children.isEmpty())
        return NULL;
    QScrollArea* scrollArea;
    for (int i = 0; i < children.size(); i++) {
        child = findFirstChildClassOf<QScrollArea>(children.at(i)->children());
        if (child == NULL)
            continue;
        scrollArea = (QScrollArea*) child;
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
QObject* MainWindow::findFirstChildClassOf(const QList<QObject*> &children) {
    QObject* child = NULL;
    for (int i = 0; i < children.size(); i++) {
        if (typeid(*children.at(i)) == typeid(T)) {
            child = children.at(i);
            break;
        } else
            child = NULL;
    }
    return child;
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

    /*if (argbImage.isGrayscale()) {
        cv::Mat gMat;
        cv::cvtColor (bgrMat, gMat, CV_BGR2GRAY);
        cv::Mat result;
        equalizeHist (gMat, result);
        cv::cvtColor (result, bgrMat, CV_GRAY2BGR);
    } else
        return;*/
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
    /*if (argbImage.isGrayscale()) {
        cv::Mat gMat;
        cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
        cv::Mat result (gMat.rows, gMat.cols, CV_8U);
        cv::Mat_<uchar>::iterator itr = result.begin<uchar>();
        cv::Mat_<uchar>::const_iterator it = gMat.begin<uchar>();
        cv::Mat_<uchar>::const_iterator itend = gMat.end<uchar>();
        for(; it != itend; ++it, ++itr)
            *itr = lookup[*it];
        cv::cvtColor(result, bgrMat, CV_GRAY2BGR);
    } else {
        cv::MatIterator_<cv::Vec3b> it, end;
        for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
            (*it)[0] = lookup[(*it)[0]];
            (*it)[1] = lookup[(*it)[1]];
            (*it)[2] = lookup[(*it)[2]];
        }
    }*/
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
    this->statusBar()->showMessage(tr("Calibration d'Histogramme(%1;%2): ").arg(seuil1).arg(seuil2));
    QString titre = QString("Calibration d'Histogramme(%1;%2): ").arg(seuil1).arg(seuil2) + windowTitle[qHash(label)];
    calculerCalibration(image, titre, seuil1, seuil2);
}

void MainWindow::calculerCalibration (QImage& argbImage, QString titre, double valeurMin, double valeurMax) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    /*int min_0 = 256, min_1 = 256, min_2 = 256;
    int max_0 = -1, max_1 = -1, max_2 = -1;
    int i_0 = 0, i_1 = 0, i_2 = 0;
    cv::MatIterator_<cv::Vec3b> it, end;
    for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
        i_0 = (*it)[0];
        i_1 = (*it)[1];
        i_2 = (*it)[2];
        if (i_0 < min_0) min_0 = i_0;
        if (i_0 > max_0) max_0 = i_0;
        if (i_1 < min_1) min_1 = i_1;
        if (i_1 > max_1) max_1 = i_1;
        if (i_2 < min_2) min_2 = i_2;
        if (i_2 > max_2) max_2 = i_2;
    }
    double m_0 = (valeurMax - valeurMin)/(max_0 - min_0);
    double b_0 = valeurMin - m_0 * min_0;
    double m_1 = (valeurMax - valeurMin)/(max_1 - min_1);
    double b_1 = valeurMin - m_1 * min_1;
    double m_2 = (valeurMax - valeurMin)/(max_2 - min_2);
    double b_2 = valeurMin - m_2 * min_2;
    uchar lookup_0 [256], lookup_1 [256], lookup_2 [256];

    for(int i = 0; i < min_0; i++)
        lookup_0[i] = 0;
    for(int i = min_0; i <= max_0; i++)
        lookup_0[i] = round(m_0 * i + b_0);
    for(int i = max_0 + 1; i < 256; i++)
        lookup_0[i] = 0;

    for(int i = 0; i < min_1; i++)
        lookup_1[i] = 0;
    for(int i = min_1; i <= max_1; i++)
        lookup_1[i] = round(m_1 * i + b_1);
    for(int i = max_0 + 1; i < 256; i++)
        lookup_1[i] = 0;

    for(int i = 0; i < min_2; i++)
        lookup_2[i] = 0;
    for(int i = min_2; i <= max_2; i++)
        lookup_2[i] = round(m_2 * i + b_2);
    for(int i = max_2 + 1; i < 256; i++)
        lookup_2[i] = 0;

    for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
        (*it)[0] = lookup_0[(*it)[0]];
        (*it)[1] = lookup_1[(*it)[1]];
        (*it)[2] = lookup_2[(*it)[2]];
    }*/
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
    this->statusBar()->showMessage(tr("Exponentielle"));
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
    this->statusBar()->showMessage(tr("Logarithmique"));
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
        this->statusBar()->showMessage(msg);
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
        this->statusBar()->showMessage(msg);
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
        this->statusBar()->showMessage(msg);
        return;
    }
    bool ok;
    double alpha = QInputDialog::getDouble(this, tr("Combinaison"), tr("Pourcentage (entre 0 et 100): "), 50, 0, 100, 2, &ok, 0);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Alpha = %1").arg(alpha));
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
        this->statusBar()->showMessage(msg);
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

    cv::Mat dst(bgrMatG.rows, bgrMatD.cols, bgrMatG.type());
    cv::MatIterator_<cv::Vec3b> it1, it2, it3, end;
    for(it1 = bgrMatG.begin<cv::Vec3b>(), it2 = bgrMatD.begin<cv::Vec3b>(), it3 = dst.begin<cv::Vec3b>(), end = bgrMatG.end<cv::Vec3b>(); it1 != end; ++it1, ++it2, ++it3) {
        (*it3)[0] = std::min((*it1)[0], (*it2)[0]);
        (*it3)[1] = std::min((*it1)[1], (*it2)[1]);
        (*it3)[2] = std::min((*it1)[2], (*it2)[2]);
    }

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
        this->statusBar()->showMessage(msg);
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

    cv::Mat dst(bgrMatG.rows, bgrMatD.cols, bgrMatG.type());
    cv::MatIterator_<cv::Vec3b> it1, it2, it3, end;
    for(it1 = bgrMatG.begin<cv::Vec3b>(), it2 = bgrMatD.begin<cv::Vec3b>(), it3 = dst.begin<cv::Vec3b>(), end = bgrMatG.end<cv::Vec3b>(); it1 != end; ++it1, ++it2, ++it3) {
        (*it3)[0] = std::max((*it1)[0], (*it2)[0]);
        (*it3)[1] = std::max((*it1)[1], (*it2)[1]);
        (*it3)[2] = std::max((*it1)[2], (*it2)[2]);
    }

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
        this->statusBar()->showMessage(msg);
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

    cv::Mat dst(bgrMatG.rows, bgrMatD.cols, bgrMatG.type());
    cv::MatIterator_<cv::Vec3b> it1, it2, it3, end;
    for(it1 = bgrMatG.begin<cv::Vec3b>(), it2 = bgrMatD.begin<cv::Vec3b>(), it3 = dst.begin<cv::Vec3b>(), end = bgrMatG.end<cv::Vec3b>(); it1 != end; ++it1, ++it2, ++it3) {
        (*it3)[0] = (*it1)[0] & (*it2)[0];
        (*it3)[1] = (*it1)[1] & (*it2)[1];
        (*it3)[2] = (*it1)[2] & (*it2)[2];
    }

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
        this->statusBar()->showMessage(msg);
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

    cv::Mat dst(bgrMatG.rows, bgrMatD.cols, bgrMatG.type());
    cv::MatIterator_<cv::Vec3b> it1, it2, it3, end;
    for(it1 = bgrMatG.begin<cv::Vec3b>(), it2 = bgrMatD.begin<cv::Vec3b>(), it3 = dst.begin<cv::Vec3b>(), end = bgrMatG.end<cv::Vec3b>(); it1 != end; ++it1, ++it2, ++it3) {
        (*it3)[0] = (*it1)[0] | (*it2)[0];
        (*it3)[1] = (*it1)[1] | (*it2)[1];
        (*it3)[2] = (*it1)[2] | (*it2)[2];
    }

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
        this->statusBar()->showMessage(msg);
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

    cv::Mat dst(bgrMatG.rows, bgrMatD.cols, bgrMatG.type());
    cv::MatIterator_<cv::Vec3b> it1, it2, it3, end;
    for(it1 = bgrMatG.begin<cv::Vec3b>(), it2 = bgrMatD.begin<cv::Vec3b>(), it3 = dst.begin<cv::Vec3b>(), end = bgrMatG.end<cv::Vec3b>(); it1 != end; ++it1, ++it2, ++it3) {
        (*it3)[0] = (*it1)[0] ^ (*it2)[0];
        (*it3)[1] = (*it1)[1] ^ (*it2)[1];
        (*it3)[2] = (*it1)[2] ^ (*it2)[2];
    }

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

    cv::MatIterator_<cv::Vec3b> it, end;
    for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
        (*it)[0] = ~(*it)[0];
        (*it)[1] = ~(*it)[1];
        (*it)[2] = ~(*it)[2];
    }

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherPlanBinaire (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int bit = QInputDialog::getInt(this, tr("Plan Binaire"), tr("Bit (entre 1 et 8): "), 4, 1, 8, 1, &ok, 0);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Plan Binaire(%1): ").arg(bit));
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
    this->statusBar()->showMessage(tr("Quantification(%1 bits): ").arg(bits));
    QString titre = QString("Quantification(%1 bits): ").arg(bits) + windowTitle[qHash(label)];
    calculerQuantification(image, titre, bits);
}

void MainWindow::calculerQuantification (QImage& argbImage, QString titre, int bits) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);
    int masque = (255>>(8-bits))<<(8-bits); //suite de '1' repetee "bits" fois (11111..0)

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
    this->statusBar()->showMessage(tr("Changement d'Échelle(%1;%2): ").arg(dimX).arg(dimY));
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
    this->statusBar()->showMessage(tr("Rotation(%1°;%2): ").arg(angle).arg(zoom));
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
    this->statusBar()->showMessage(tr("Rotation Interpolée(%1°;%2): ").arg(angle).arg(zoom));
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
/*
 void MainWindow::calculerVuePerspective (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::Point2f srcTri[3];
    cv::Point2f dstTri[3];

    cv::Mat rot_mat( 2, 3, CV_32FC1 );
    cv::Mat warp_mat( 2, 3, CV_32FC1 );
    cv::Mat src, warp_dst, warp_rotate_dst;

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
    warp_mat = cv::getAffineTransform( srcTri, dstTri );

    /// Apply the Affine Transform just found to the src image
    cv::warpAffine( src, warp_dst, warp_mat, warp_dst.size() );

    /// Compute a rotation matrix with respect to the center of the image
    cv::Point center = cv::Point( warp_dst.cols/2, warp_dst.rows/2 );
    double angle = -50.0;
    double scale = 0.6;

    /// Get the rotation matrix with the specifications above
    rot_mat = cv::getRotationMatrix2D( center, angle, scale );

    /// Rotate the warped image
    cv::warpAffine( warp_dst, warp_rotate_dst, rot_mat, warp_dst.size() );

    bgrMat = warp_rotate_dst;

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}
*/

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
    this->statusBar()->showMessage(tr("Bruit Uniforme(%1): ").arg(valeur));
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
    this->statusBar()->showMessage(tr("Poivre et Sel(%1%): ").arg(pourcentage));
    QString titre = QString("Poivre et Sel(%1%): ").arg(pourcentage) + windowTitle[qHash(label)];
    calculerBruitPoivreEtSel (image, titre, pourcentage/100);
}

void MainWindow::calculerBruitPoivreEtSel (QImage& argbImage, QString titre, double pourcentage) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

/*
Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() != sizeof(uchar));

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    uchar* p;
    for(i = 0; i < nRows; ++i)
    {
        p = I.ptr<uchar>(i);
        for ( j = 0; j < nCols; ++j)
        {
            p[j] = table[p[j]];
        }
    }
    return I;
}
*/
    /*
    uchar lookup [256];
    for (int i = 0; i < 256; i++)
        lookup[i] = 255 - i;
    int rows = bgrMat.rows;
    int cols = bgrMat.cols * bgrMat.channels();
    if (bgrMat.isContinuous()) {
        cols *= rows;
        rows = 1;
    }
    uchar* p;
    for (int i = 0; i < rows; i++) {
        p = bgrMat.ptr<uchar>(i);
        for (int j = 0; j < cols; j+=3) {
            *(p + j + 0) = lookup[*(p + j + 0)];
            *(p + j + 1) = lookup[*(p + j + 1)];
            *(p + j + 2) = lookup[*(p + j + 2)];
        }
    }
    */
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
    this->statusBar()->showMessage(tr("Image Uniforme(%1)").arg(valeur));
    QString titre = QString("Image Uniforme(%1)").arg(valeur);
    calculerUniforme(image, titre, valeur);
}

void MainWindow::afficherUniforme (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int valeur = QInputDialog::getInt(this, tr("Image Uniforme"), tr("Valeur (entre 0 et 255)"), 0, 0, 255, 1, &ok, 0);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Image Uniforme(%1)").arg(valeur));
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
    cv::Mat bgrMat(argbImage.height(), argbImage.width(), CV_32FC3, cv::Scalar(1, 1, 270));
    //cv::cvtColor(bgrMat, bgrMat, CV_BGR2HLS_FULL);

    int rows = bgrMat.rows;
    int cols = bgrMat.cols * bgrMat.channels();
    float* p = (float*)bgrMat.data;
    /*std::cerr << bgrMat.dataend - bgrMat.data << std::endl;
    std::cerr << cols * rows * 4 << std::endl;
    std::cerr << (unsigned long int)bgrMat.dataend << std::endl;
    std::cerr << p + (rows-1)*cols+(cols-1) + 1 << std::endl;*/
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols-1; j++) {
            *(p + i*cols+j + 0) = (float)((cols-1)-j)/(cols-1);
            *(p + i*cols+j + 1) = (float)((cols-1)-j)/(cols-1);
        }
    }
    bgrMat.convertTo(bgrMat, CV_8U, 255);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

//menu filtrage
void MainWindow::afficherMoyenneur3x3 (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("Moyenneur 3x3: ") + windowTitle[qHash(label)];
    calculerMoyenneur3x3  (image, titre, cv::Point(-1,-1), BORDER_TYPE);
}

void MainWindow::calculerMoyenneur3x3 (QImage& argbImage, QString titre, cv::Point anchor, int borderType) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

/*
void cv::blur( InputArray src, OutputArray dst,
           Size ksize, Point anchor, int borderType )
{
    boxFilter( src, dst, -1, ksize, anchor, true, borderType );
}

void cv::boxFilter( InputArray _src, OutputArray _dst, int ddepth,
                Size ksize, Point anchor,
                bool normalize, int borderType )
{
    Mat src = _src.getMat();
    int sdepth = src.depth(), cn = src.channels();
    if( ddepth < 0 )
        ddepth = sdepth;
    _dst.create( src.size(), CV_MAKETYPE(ddepth, cn) );
    Mat dst = _dst.getMat();
    if( borderType != BORDER_CONSTANT && normalize )
    {
        if( src.rows == 1 )
            ksize.height = 1;
        if( src.cols == 1 )
            ksize.width = 1;
    }
#ifdef HAVE_TEGRA_OPTIMIZATION
    if ( tegra::box(src, dst, ksize, anchor, normalize, borderType) )
        return;
#endif

    Ptr<FilterEngine> f = createBoxFilter( src.type(), dst.type(),
                        ksize, anchor, normalize, borderType );
    f->apply( src, dst );
}

cv::Ptr<cv::FilterEngine> cv::createBoxFilter( int srcType, int dstType, Size ksize,
                    Point anchor, bool normalize, int borderType )
{
    int sdepth = CV_MAT_DEPTH(srcType);
    int cn = CV_MAT_CN(srcType), sumType = CV_64F;
    if( sdepth <= CV_32S && (!normalize ||
        ksize.width*ksize.height <= (sdepth == CV_8U ? (1<<23) :
            sdepth == CV_16U ? (1 << 15) : (1 << 16))) )
        sumType = CV_32S;
    sumType = CV_MAKETYPE( sumType, cn );

    Ptr<BaseRowFilter> rowFilter = getRowSumFilter(srcType, sumType, ksize.width, anchor.x );
    Ptr<BaseColumnFilter> columnFilter = getColumnSumFilter(sumType,
        dstType, ksize.height, anchor.y, normalize ? 1./(ksize.width*ksize.height) : 1);

    return Ptr<FilterEngine>(new FilterEngine(Ptr<BaseFilter>(0), rowFilter, columnFilter,
           srcType, dstType, sumType, borderType ));
}
*/
 /*
    int srcType = CV_8UC3, dstType = CV_8UC3;
    cv::Size ksize = cv::Size(3, 3);
    cv::Point _anchor = cv::Point(-1,-1);
    bool normalize = true;
    int sdepth = CV_MAT_DEPTH(srcType);
    int cn = CV_MAT_CN(srcType), sumType = CV_64F;
    if( sdepth <= CV_32S && (!normalize ||
                             ksize.width*ksize.height <= (sdepth == CV_8U ? (1<<23) :
                                                          sdepth == CV_16U ? (1 << 15) : (1 << 16))) )
        sumType = CV_32S;
    sumType = CV_MAKETYPE( sumType, cn );

    cv::Ptr<cv::BaseRowFilter> rowFilter = cv::getRowSumFilter(srcType, sumType, ksize.width, _anchor.x );
    cv::Ptr<cv::BaseColumnFilter> columnFilter = cv::getColumnSumFilter(sumType,
                                                            dstType, ksize.height, _anchor.y, normalize ? 1./(ksize.width*ksize.height) : 1);
    std::cerr << rowFilter;
    std::cerr << columnFilter;
*/
    cv::Mat kern = (cv::Mat_<uchar>(3,3) <<
    1, 1, 1,
    1, 1, 1,
    1, 1, 1);
    cv::Mat res;
    cv::filter2D(bgrMat, res, CV_16UC3, kern, anchor, 0, borderType);
    bgrMat = res * 1.d/9;
    bgrMat.convertTo(bgrMat, CV_8U, 1, 0);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

/*** calculer le temps d'execution
double t = (double)getTickCount();
// do something ...
t = ((double)getTickCount() - t)/getTickFrequency();
*/

void MainWindow::afficherMoyenneurNxN (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int N = QInputDialog::getInt(this, tr("Moyenneur NxN séparable"), tr("N: "), 3, 3, 31, 1, &ok, 0);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Moyenneur %1x%2 séparable: ").arg(N).arg(N));
    QString titre = QString("Moyenneur %1x%2 séparable: ").arg(N).arg(N) + windowTitle[qHash(label)];
    calculerMoyenneurNxN (image, titre,cv::Size (N, N), cv::Point (-1, -1), BORDER_TYPE);
}

void MainWindow::calculerMoyenneurNxN (QImage& argbImage, QString titre, cv::Size ksize, cv::Point anchor, int borderType) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::blur (bgrMat, bgrMat, ksize, anchor, borderType);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherLaplacien (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    double gain;
    int offset;
    bool ok;
    DoubleIntDialog d(this, QString("Laplacien"), QString("Gain (entre 1 et 30): "), 1, 1, 30, 2, QString("Offset (entre 0 et 255): "), 0, 0, 255, 1);
    d.run(gain, offset, ok);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Laplacien(%1;%2): ").arg(gain).arg(offset));
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
    this->statusBar()->showMessage(tr("Filtre Médian %1x%2").arg(N).arg(N));
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
    this->statusBar()->showMessage(tr("V-Filtre(%1): ").arg(N));
    QString titre = QString("V-Filtre(%1): ").arg(N) + windowTitle[qHash(label)];
    calculerVFiltre(image, titre, N);
}

void MainWindow::calculerVFiltre (QImage& argbImage, QString titre, int ksize) {
    if (ksize % 2 == 0)
        return;
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    /*if (argbImage.isGrayscale()) {
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
    if (argbImage.isGrayscale()) {
        cv::Mat gMat;
        cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
        cv::Mat result (gMat.rows, gMat.cols, CV_8U);
        cv::Mat_<uchar>::iterator itr = result.begin<uchar>();
        cv::Mat_<uchar>::const_iterator it = gMat.begin<uchar>();
        cv::Mat_<uchar>::const_iterator itend = gMat.end<uchar>();
        for(; it != itend; ++it, ++itr)
            *itr = lookup[*it];
        cv::cvtColor(result, bgrMat, CV_GRAY2BGR);
    } else {
        cv::MatIterator_<cv::Vec3b> it, end;
        for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
            (*it)[0] = lookup[(*it)[0]];
            (*it)[1] = lookup[(*it)[1]];
            (*it)[2] = lookup[(*it)[2]];
        }
    }*/
    /*
    cv::Mat q0(magI, cv::Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    cv::Mat q1(magI, cv::Rect(cx, 0, cx, cy));  // Top-Right
    cv::Mat q2(magI, cv::Rect(0, cy, cx, cy));  // Bottom-Left
    cv::Mat q3(magI, cv::Rect(cx, cy, cx, cy)); // Bottom-Right
    meanStdDev()



    if (argbImage.isGrayscale()) {
        cv::Mat gMat;
        cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
        cv::Mat result (gMat.rows, gMat.cols, CV_8U);
        cv::MatIterator_<uchar> it1, it2, end;
        int x, y, size = (ksize - 1)/2;
        double m0, s0, m1, s1, m2, s2, m3, s3, m4, s4;
        for(it1 = result.begin<uchar>(), it2 = gMat.begin<uchar>(), end = gMat.end<uchar>(); it2 != end; ++it1, ++ it2) {
            x = it2.pos().x;
            y = it2.pos().y;
            cv::Mat q0(gMat, cv::Rect(x-size, y-size, x, y)); // Top-Left - Create a ROI per quadrant
            cv::Mat q1(gMat, cv::Rect(x, y-size, x+size, y)); // Top-Right
            cv::Mat q2(gMat, cv::Rect(x-size, y, x, y+size)); // Bottom-Left
            cv::Mat q3(gMat, cv::Rect(x, y, x+size, y+size)); // Bottom-Right
            cv::Mat q4(gMat, cv::Rect(x, y, x+size, y+size)); // Bottom-Right
            *it1 = cv::saturate_cast<uchar>(*it2);
        }
        cv::cvtColor(result, bgrMat, CV_GRAY2BGR);
    } else {
        //cv::MatIterator_<cv::Vec3b> it, end;
        //for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
            //(*it)[0] = lookup[(*it)[0]];
            //(*it)[1] = lookup[(*it)[1]];
            //(*it)[2] = lookup[(*it)[2]];
        //}
    }
        cv::Mat gMat;
        cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
        int cols = gMat.cols, rows = gMat.rows;
        uchar* p = (uchar*)gMat.data;
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                *(p + y*cols+x) = cv::saturate_cast<uchar>(255*((cols-1)-x)/(cols-1)); //hor grad
                *(p + y*cols+x) = cv::saturate_cast<uchar>(255*(y)/(cols-1));          //hor grad (inv)
                *(p + y*cols+x) = cv::saturate_cast<uchar>(255*((cols-1)-y)/(cols-1)); //ver grad
                *(p + y*cols+x) = cv::saturate_cast<uchar>(255*(y)/(cols-1));          //ver grad (inv)
            }
        }
        cv::cvtColor(gMat, bgrMat, CV_GRAY2BGR);
    */
    if (argbImage.isGrayscale()) {
        cv::Mat gMat;
        cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
        int rows = gMat.rows, cols = gMat.cols;
        int size = (ksize - 1)/2;//, x, y;
        double best_mean, best_stddev, mean, stddev;//, m0, s0, m1, s1, m2, s2, m3, s3, m4, s4;
        //cv::Mat result (rows, cols, CV_8U);
        cv::Mat result = gMat.clone();
        //cv::MatIterator_<uchar> it1, it2, end;
        /*for(it1 = result.begin<uchar>(), it2 = gMat.begin<uchar>(), end = gMat.end<uchar>(); it2 != end; ++it1, ++ it2) {
            x = it2.pos().x;
            y = it2.pos().y;
            std::cerr << x << ' ' << y << std::endl;
            cv::Mat q0(gMat, cv::Rect(std::max(x-ksize, 0), std::max(y-ksize, 0), x, y));       // Top-Left - Create a ROI per quadrant
            cv::Mat q1(gMat, cv::Rect(x, std::max(y-ksize, 0), std::min(x+ksize, cols), y));    // Top-Right
            cv::Mat q2(gMat, cv::Rect(std::max(x-ksize, 0), y, x, std::min(y+ksize, rows)));    // Bottom-Left
            cv::Mat q3(gMat, cv::Rect(x, y, std::min(x+ksize, cols), std::min(y+ksize, rows))); // Bottom-Right
            cv::Mat q4(gMat, cv::Rect(std::max(x-size, 0), std::max(y-size, 0), std::min(x+size+1, cols), std::min(y+size+1, rows))); // Center
            std::cerr << q0 << q1 << q2 << q3 << q4 << std::endl;
            // *it1 = cv::saturate_cast<uchar>(*it2);
            // if (x == 4) break;
        }*/
        /*uchar* p = (uchar*)bgrMat.data;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols-1; j++) {
                *(p + i*cols+j) = (float)((cols-1)-j)/(cols-1);
            }
        }*/
        //uchar* p = (uchar*)gMat.data;
        uchar* p = (uchar*)result.data;
        //for (int y = 0; y < rows; y++) {
            //for (int x = 0; x < cols; x++) {
                //*(p + y*cols+x) = p + y*cols+x - gMat.datastart;
            //}
        //}
/*
        for (int y = 0; y < ksize-1; y++) {
            for (int x = 0; x < ksize-1; x++) {
                std::cerr << x << ' ' << y << std::endl;
                std::cerr << cv::Rect(std::max(x-size, 0), std::max(y-size, 0), x+1, y+1) << std::endl;
                std::cerr << cv::Rect(x, std::max(y-ksize+1, 0), ksize, y+1) << std::endl;
                std::cerr << cv::Rect(std::max(x-ksize+1, 0), y, x+1, ksize) << std::endl;
                std::cerr << cv::Rect(x, y, ksize, ksize) << std::endl;
                std::cerr << cv::Rect(std::max(x-size, 0), std::max(y-size, 0), size+1, size+1) << std::endl;
                cv::Mat q0(gMat, cv::Rect(std::max(x-size, 0), std::max(y-size, 0), x+1, y+1));       // Top-Left
                cv::Mat q1(gMat, cv::Rect(x, std::max(y-ksize+1, 0), ksize, y+1));                    // Top-Right
                cv::Mat q2(gMat, cv::Rect(std::max(x-ksize+1, 0), y, x+1, ksize));                    // Bottom-Left
                cv::Mat q3(gMat, cv::Rect(x, y, ksize, ksize));                                       // Bottom-Right
                cv::Mat q4(gMat, cv::Rect(std::max(x-size, 0), std::max(y-size, 0), size+1, size+1)); // Center
                cv::Mat mean_m, stddev_m;
                best_mean = -1; best_stddev = 1.79769e+308;
                std::cerr << q0 << q1 << q2 << q3 << q4 << std::endl << std::endl;

                cv::meanStdDev(q0, mean_m, stddev_m, cv::noArray());
                mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                std::cerr << mean << ' ' << stddev << ' ' << best_mean << std::endl << std::endl;

                cv::meanStdDev(q1, mean_m, stddev_m, cv::noArray());
                mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                std::cerr << mean << ' ' << stddev << ' ' << best_mean << std::endl << std::endl;

                cv::meanStdDev(q2, mean_m, stddev_m, cv::noArray());
                mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                std::cerr << mean << ' ' << stddev << ' ' << best_mean << std::endl << std::endl;

                cv::meanStdDev(q3, mean_m, stddev_m, cv::noArray());
                mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                std::cerr << mean << ' ' << stddev << ' ' << best_mean << std::endl << std::endl;

                cv::meanStdDev(q4, mean_m, stddev_m, cv::noArray());
                mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}
                std::cerr << mean << ' ' << stddev << ' ' << best_mean << std::endl << std::endl;

                *(p + y*cols+x) = best_mean;
            }
        }
*/
        for (int y = 0; y < ksize-1; y++) {
            for (int x = 0; x < ksize-1; x++) {
                /*std::cerr << x << ' ' << y << std::endl;
                std::cerr << cv::Rect(0, 0, x+1, y+1) << std::endl;
                std::cerr << cv::Rect(x, 0, ksize, y+1) << std::endl;
                std::cerr << cv::Rect(0, y, x+1, ksize) << std::endl;
                std::cerr << cv::Rect(x, y, ksize, ksize) << std::endl;
                std::cerr << cv::Rect(0, 0, size+1, size+1) << std::endl;*/
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
                /*cv::meanStdDev(q0, mean_m, stddev_m, cv::noArray());
                mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}

                cv::meanStdDev(q1, mean_m, stddev_m, cv::noArray());
                mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}

                cv::meanStdDev(q2, mean_m, stddev_m, cv::noArray());
                mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}

                cv::meanStdDev(q3, mean_m, stddev_m, cv::noArray());
                mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}

                cv::meanStdDev(q4, mean_m, stddev_m, cv::noArray());
                mean = mean_m.at<double>(0, 0);stddev = stddev_m.at<double>(0,0);
                if(stddev < best_stddev) {best_stddev = stddev; best_mean = mean;}*/

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
    } else {
        //cv::MatIterator_<cv::Vec3b> it, end;
        //for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
            //(*it)[0] = lookup[(*it)[0]];
            //(*it)[1] = lookup[(*it)[1]];
            //(*it)[2] = lookup[(*it)[2]];
        //}
    }

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
    this->statusBar()->showMessage(tr("Seuillage(%1): ").arg(seuil));
    QString titre = QString("Seuillage(%1): ").arg(seuil) + windowTitle[qHash(label)];
    calculerSeuillageManuelSimple (image, titre, seuil, 255);
}

void MainWindow::calculerSeuillageManuelSimple (QImage& argbImage, QString titre, double seuil, double maxval) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::threshold(bgrMat, bgrMat, seuil, maxval, cv::THRESH_BINARY);

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherSeuillageManuelDouble (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    int seuil1, seuil2;
    bool ok;
    IntIntDialog d(this, QString("Seuillage Double"), QString("Seuil Inférieur (entre 0 et 255): "), 80, 0, 255, 1, QString("Seuil Supérieur (entre 0 et 255): "), 240, 0, 255, 1);
    d.run(seuil1, seuil2, ok);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Seuillage Double Manuel(%1;%2): ").arg(seuil1).arg(seuil2));
    QString titre = QString("Seuillage Double Manuel(%1;%2): ").arg(seuil1).arg(seuil2) + windowTitle[qHash(label)];
    calculerSeuillageManuelDouble(image, titre, seuil1, seuil2, 0, 127, 255);
}

/*
 *cv::adaptiveThreshold(src,dst,double maxval,adaptativeMethod,thresholdType,int blockSize,double C)
 *cv::Canny(src,dst_edges,double  threshold1,double threshold2,int apertureSize=3,bool L2gradient=false)
 *cv::createDerivFilter()
 *cv::createLinearFilter()
 *cv::createMorphologyFilter()
 *cv::createSeparableLinearFilter()
 *cv::dct()
 *cv::dft()
 *cv::erode(src,dst,i_kernel,Point anchor = (-1,-1),int iterations=1,border,const Scalar& borderValue=morphologyDefaultBorderValue)
 *cv::meanStdDev(src, mean, stddev, mask=noArray())
 *cv::Mahalanobis(src1, src2, icovar)
 *cv::Mahalonobis(src1, src2, icovar)
 *cv::Laplacian(src,dst,ddepth,int ksize=3,double scale=1,double delta=0,borderType=BORDER_DEFAULT)
 *cv::Scharr(src,dst,ddepth,int dx,int dy,int ksize=3,double scale=1,double delta=0,borderType=BORDER_DEFAULT)
 *cv::Sobel(src,dst,ddepth,int dx=0 ou 1,int dy=0 ou 1,int ksize=3,double scale=1,double delta=0,borderType=BORDER_DEFAULT)
 */
void MainWindow::calculerSeuillageManuelDouble (QImage& argbImage, QString titre, double seuilBas, double seuilHaut, double minVal, double midVal, double maxVal) {

    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

/*
    uchar lookup [256];
    for(int i = 0; i < 256; i++)
        lookup[i] = 255 - i;
    cv::MatIterator_<cv::Vec3b> it, end;
    for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
        (*it)[0] = lookup[(*it)[0]];
        (*it)[1] = lookup[(*it)[1]];
        (*it)[2] = lookup[(*it)[2]];
    }
*/
    cv::MatIterator_<cv::Vec3b> it, end;
    for(it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
        (*it)[0] = (*it)[0] < seuilBas ? minVal : (*it)[0] > seuilHaut ? maxVal : midVal;
        (*it)[1] = (*it)[1] < seuilBas ? minVal : (*it)[1] > seuilHaut ? maxVal : midVal;
        (*it)[2] = (*it)[2] < seuilBas ? minVal : (*it)[2] > seuilHaut ? maxVal : midVal;
    }

    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherSeuillageParHysteresis (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    int seuil1, seuil2;
    bool ok;
    IntIntDialog d(this, QString("Seuillage par Hystérésis"), QString("Seuil Inférieur (entre 0 et 255): "), 80, 0, 255, 1, QString("Seuil Supérieur (entre 0 et 255): "), 240, 0, 255, 1);
    d.run(seuil1, seuil2, ok);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Seuillage par Hystérésis(%1;%2): ").arg(seuil1).arg(seuil2));
    QString titre = QString("Seuillage par Hystérésis(%1;%2): ").arg(seuil1).arg(seuil2) + windowTitle[qHash(label)];
    calculerSeuillageParHysteresis (image, titre, seuil1, seuil2, 3, true);///ratio seuilHaut/seuilBas preferablement entre 3:1 et 2:1
}

void MainWindow::calculerSeuillageParHysteresis (QImage& argbImage, QString titre, int seuilBas, int seuilHaut, int ksize, bool utiliserNormeL2) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::Mat gMat;
    cv::cvtColor (bgrMat, gMat, CV_BGR2GRAY);
    cv::blur (gMat, gMat, cv::Size(3,3), cv::Point(-1,-1), BORDER_TYPE);
    //cv::GaussianBlur (gMat, gMat, cv::Size(3,3), 0, 0, BORDER_TYPE);
    cv::Mat edges;
    cv::Canny (gMat, edges, seuilBas, seuilHaut, ksize, utiliserNormeL2);
    cv::Mat dst (bgrMat.size(), bgrMat.type(), cv::Scalar::all(0));
    bgrMat.copyTo (dst, edges);

    cvMatToQImage(dst, argbImage);
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
    this->statusBar()->showMessage(tr("Gradient Sobel %1(%2;%3): ").arg(type == SOBEL_NORME ? "[Norme]" : type == SOBEL_X ? "X" : type == SOBEL_Y ? "Y" : "").arg(gain).arg(offset));
    QString titre = QString("Gradient Sobel %1(%2;%3): ").arg(type == SOBEL_NORME ? "[Norme]" : type == SOBEL_X ? "X" : type == SOBEL_Y ? "Y" : "").arg(gain).arg(offset) + windowTitle[qHash(label)];
    calculerGradientSobel (image, titre, type, 3, gain, offset, BORDER_TYPE);
}

void MainWindow::calculerGradientSobel (QImage& argbImage, QString titre, TypeSobel type, int ksize, double gain, double offset, int borderType) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);
    /*
  Mat src, src_gray;
  Mat grad;
  char* window_name = "Sobel Demo - Simple Edge Detector";
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;

  int c;

  /// Load an image
  src = imread( argv[1] );

  if( !src.data )
  { return -1; }

  GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );

  /// Convert it to gray
  cvtColor( src, src_gray, CV_RGB2GRAY );

  /// Create window
  namedWindow( window_name, CV_WINDOW_AUTOSIZE );

  /// Generate grad_x and grad_y
  Mat grad_x, grad_y;
  Mat abs_grad_x, abs_grad_y;

  /// Gradient X
  //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
  Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
  convertScaleAbs( grad_x, abs_grad_x );

  /// Gradient Y
  //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
  Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
  convertScaleAbs( grad_y, abs_grad_y );

  /// Total Gradient (approximate)
  addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );

  imshow( window_name, grad );
    }
     */
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
        /*cv::convertScaleAbs(dst_x, dst_x);
        cv::convertScaleAbs(dst_y, dst_y);
        cv::addWeighted (dst_x, 0.5, dst_y, 0.5, 0, dst_total);*/
        //cv::imshow("Manhattan", dst_total);
        x = x.mul(x);
        y = y.mul(y);
        s = x + y;
        cv::sqrt(s, dst_total);
        cv::normalize(dst_total, dst_total, 0, 1, CV_MINMAX);
        dst_total.convertTo(dst_total, CV_8U, 255, 0);
        //cv::imshow("Euclidean", dst_total);
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
    this->statusBar()->showMessage(tr("Gradient Prewitt %1(%2;%3): ").arg(type == PREWITT_NORME ? "[Norme]" : type == PREWITT_X ? "X" : type == PREWITT_Y ? "Y" : "").arg(gain).arg(offset));
    QString titre = QString("Gradient Prewitt %1(%2;%3): ").arg(type == PREWITT_NORME ? "[Norme]" : type == PREWITT_X ? "X" : type == PREWITT_Y ? "Y" : "").arg(gain).arg(offset) + windowTitle[qHash(label)];
    calculerGradientPrewitt (image, titre, type, gain, offset, BORDER_TYPE);
}

/*
    cv::Mat kern = (cv::Mat_<uchar>(3,3) <<
    1, 1, 1,
    1, 1, 1,
    1, 1, 1);
    cv::Mat res;
    cv::filter2D(bgrMat, res, CV_16UC3, kern, anchor, 0, borderType);
    bgrMat = res * 1.d/9;
    bgrMat.convertTo(bgrMat, CV_8U, 1, 0);
*/
/*
void cv::Scharr( InputArray _src, OutputArray _dst, int ddepth, int dx, int dy,
                 double scale, double delta, int borderType )
{
    Mat src = _src.getMat();
    if (ddepth < 0)
        ddepth = src.depth();
    _dst.create( src.size(), CV_MAKETYPE(ddepth, src.channels()) );
    Mat dst = _dst.getMat();

#ifdef HAVE_TEGRA_OPTIMIZATION
    if (scale == 1.0 && delta == 0)
        if (tegra::scharr(src, dst, dx, dy, borderType))
            return;
#endif

#if defined (HAVE_IPP) && (IPP_VERSION_MAJOR >= 7)
    if(dx < 2 && dy < 2 && src.channels() == 1 && borderType == 1)
    {
        if(IPPDerivScharr(src, dst, ddepth, dx, dy, scale))
            return;
    }
#endif
    int ktype = std::max(CV_32F, std::max(ddepth, src.depth()));

    Mat kx, ky;
    getScharrKernels( kx, ky, dx, dy, false, ktype );
    if( scale != 1 )
    {
        // usually the smoothing part is the slowest to compute,
        // so try to scale it instead of the faster differenciating part
        if( dx == 0 )
            kx *= scale;
        else
            ky *= scale;
    }
    sepFilter2D( src, dst, ddepth, kx, ky, Point(-1,-1), delta, borderType );
}
static void getScharrKernels( OutputArray _kx, OutputArray _ky,
                              int dx, int dy, bool normalize, int ktype )
{
    const int ksize = 3;

    CV_Assert( ktype == CV_32F || ktype == CV_64F );
    _kx.create(ksize, 1, ktype, -1, true);
    _ky.create(ksize, 1, ktype, -1, true);
    Mat kx = _kx.getMat();
    Mat ky = _ky.getMat();

    CV_Assert( dx >= 0 && dy >= 0 && dx+dy == 1 );

    for( int k = 0; k < 2; k++ )
    {
        Mat* kernel = k == 0 ? &kx : &ky;
        int order = k == 0 ? dx : dy;
        int kerI[3];

        if( order == 0 )
            kerI[0] = 3, kerI[1] = 10, kerI[2] = 3;
        else if( order == 1 )
            kerI[0] = -1, kerI[1] = 0, kerI[2] = 1;

        Mat temp(kernel->rows, kernel->cols, CV_32S, &kerI[0]);
        double scale = !normalize || order == 1 ? 1. : 1./32;
        temp.convertTo(*kernel, ktype, scale);
    }
}


static void getSobelKernels( OutputArray _kx, OutputArray _ky,
                             int dx, int dy, int _ksize, bool normalize, int ktype )
{
    int i, j, ksizeX = _ksize, ksizeY = _ksize;
    if( ksizeX == 1 && dx > 0 )
        ksizeX = 3;
    if( ksizeY == 1 && dy > 0 )
        ksizeY = 3;

    CV_Assert( ktype == CV_32F || ktype == CV_64F );

    _kx.create(ksizeX, 1, ktype, -1, true);
    _ky.create(ksizeY, 1, ktype, -1, true);
    Mat kx = _kx.getMat();
    Mat ky = _ky.getMat();

    if( _ksize % 2 == 0 || _ksize > 31 )
        CV_Error( CV_StsOutOfRange, "The kernel size must be odd and not larger than 31" );
    vector<int> kerI(std::max(ksizeX, ksizeY) + 1);

    CV_Assert( dx >= 0 && dy >= 0 && dx+dy > 0 );

    for( int k = 0; k < 2; k++ )
    {
        Mat* kernel = k == 0 ? &kx : &ky;
        int order = k == 0 ? dx : dy;
        int ksize = k == 0 ? ksizeX : ksizeY;

        CV_Assert( ksize > order );

        if( ksize == 1 )
            kerI[0] = 1;
        else if( ksize == 3 )
        {
            if( order == 0 )
                kerI[0] = 1, kerI[1] = 2, kerI[2] = 1;
            else if( order == 1 )
                kerI[0] = -1, kerI[1] = 0, kerI[2] = 1;
            else
                kerI[0] = 1, kerI[1] = -2, kerI[2] = 1;
        }
        else
        {
            int oldval, newval;
            kerI[0] = 1;
            for( i = 0; i < ksize; i++ )
                kerI[i+1] = 0;

            for( i = 0; i < ksize - order - 1; i++ )
            {
                oldval = kerI[0];
                for( j = 1; j <= ksize; j++ )
                {
                    newval = kerI[j]+kerI[j-1];
                    kerI[j-1] = oldval;
                    oldval = newval;
                }
            }

            for( i = 0; i < order; i++ )
            {
                oldval = -kerI[0];
                for( j = 1; j <= ksize; j++ )
                {
                    newval = kerI[j-1] - kerI[j];
                    kerI[j-1] = oldval;
                    oldval = newval;
                }
            }
        }

        Mat temp(kernel->rows, kernel->cols, CV_32S, &kerI[0]);
        double scale = !normalize ? 1. : 1./(1 << (ksize-order-1));
        temp.convertTo(*kernel, ktype, scale);
    }
}














void icvSepConvSmall3_32f( float* src, int src_step, float* dst, int dst_step,
            CvSize src_size, const float* kx, const float* ky, float* buffer )
{
    int  dst_width, buffer_step = 0;
    int  x, y;
    bool fast_kx = true, fast_ky = true;

    assert( src && dst && src_size.width > 2 && src_size.height > 2 &&
            (src_step & 3) == 0 && (dst_step & 3) == 0 &&
            (kx || ky) && (buffer || !kx || !ky));

    src_step /= sizeof(src[0]);
    dst_step /= sizeof(dst[0]);

    dst_width = src_size.width - 2;

    if( !kx )
    {
        \* set vars, so that vertical convolution
           will write results into destination ROI and
           horizontal convolution won't run *\
        src_size.width = dst_width;
        buffer_step = dst_step;
        buffer = dst;
        dst_width = 0;
    }
    else
        fast_kx = kx[1] == 0.f && kx[0] == -kx[2] && kx[0] == -1.f;

    assert( src_step >= src_size.width && dst_step >= dst_width );

    src_size.height -= 2;
    if( !ky )
    {
        \* set vars, so that vertical convolution won't run and
           horizontal convolution will write results into destination ROI *\
        src_size.height += 2;
        buffer_step = src_step;
        buffer = src;
        src_size.width = 0;
    }
    else
        fast_ky = ky[1] == 0.f && ky[0] == -ky[2] && ky[0] == -1.f;

    for( y = 0; y < src_size.height; y++, src += src_step,
                                          dst += dst_step,
                                          buffer += buffer_step )
    {
        float* src2 = src + src_step;
        float* src3 = src + src_step*2;
        if( fast_ky )
            for( x = 0; x < src_size.width; x++ )
            {
                buffer[x] = (float)(src3[x] - src[x]);
            }
        else
            for( x = 0; x < src_size.width; x++ )
            {
                buffer[x] = (float)(ky[0]*src[x] + ky[1]*src2[x] + ky[2]*src3[x]);
            }

        if( fast_kx )
            for( x = 0; x < dst_width; x++ )
            {
                dst[x] = (float)(buffer[x+2] - buffer[x]);
            }
        else
            for( x = 0; x < dst_width; x++ )
            {
                dst[x] = (float)(kx[0]*buffer[x] + kx[1]*buffer[x+1] + kx[2]*buffer[x+2]);
            }
    }
}


\****************************************************************************************\
                             Sobel & Scharr Derivative Filters
\****************************************************************************************\

namespace cv
{

static void getScharrKernels( OutputArray _kx, OutputArray _ky,
                              int dx, int dy, bool normalize, int ktype )
{
    const int ksize = 3;

    CV_Assert( ktype == CV_32F || ktype == CV_64F );
    _kx.create(ksize, 1, ktype, -1, true);
    _ky.create(ksize, 1, ktype, -1, true);
    Mat kx = _kx.getMat();
    Mat ky = _ky.getMat();

    CV_Assert( dx >= 0 && dy >= 0 && dx+dy == 1 );

    for( int k = 0; k < 2; k++ )
    {
        Mat* kernel = k == 0 ? &kx : &ky;
        int order = k == 0 ? dx : dy;
        int kerI[3];

        if( order == 0 )
            kerI[0] = 3, kerI[1] = 10, kerI[2] = 3;
        else if( order == 1 )
            kerI[0] = -1, kerI[1] = 0, kerI[2] = 1;

        Mat temp(kernel->rows, kernel->cols, CV_32S, &kerI[0]);
        double scale = !normalize || order == 1 ? 1. : 1./32;
        temp.convertTo(*kernel, ktype, scale);
    }
}


static void getSobelKernels( OutputArray _kx, OutputArray _ky,
                             int dx, int dy, int _ksize, bool normalize, int ktype )
{
    int i, j, ksizeX = _ksize, ksizeY = _ksize;
    if( ksizeX == 1 && dx > 0 )
        ksizeX = 3;
    if( ksizeY == 1 && dy > 0 )
        ksizeY = 3;

    CV_Assert( ktype == CV_32F || ktype == CV_64F );

    _kx.create(ksizeX, 1, ktype, -1, true);
    _ky.create(ksizeY, 1, ktype, -1, true);
    Mat kx = _kx.getMat();
    Mat ky = _ky.getMat();

    if( _ksize % 2 == 0 || _ksize > 31 )
        CV_Error( CV_StsOutOfRange, "The kernel size must be odd and not larger than 31" );
    vector<int> kerI(std::max(ksizeX, ksizeY) + 1);

    CV_Assert( dx >= 0 && dy >= 0 && dx+dy > 0 );

    for( int k = 0; k < 2; k++ )
    {
        Mat* kernel = k == 0 ? &kx : &ky;
        int order = k == 0 ? dx : dy;
        int ksize = k == 0 ? ksizeX : ksizeY;

        CV_Assert( ksize > order );

        if( ksize == 1 )
            kerI[0] = 1;
        else if( ksize == 3 )
        {
            if( order == 0 )
                kerI[0] = 1, kerI[1] = 2, kerI[2] = 1;
            else if( order == 1 )
                kerI[0] = -1, kerI[1] = 0, kerI[2] = 1;
            else
                kerI[0] = 1, kerI[1] = -2, kerI[2] = 1;
        }
        else
        {
            int oldval, newval;
            kerI[0] = 1;
            for( i = 0; i < ksize; i++ )
                kerI[i+1] = 0;

            for( i = 0; i < ksize - order - 1; i++ )
            {
                oldval = kerI[0];
                for( j = 1; j <= ksize; j++ )
                {
                    newval = kerI[j]+kerI[j-1];
                    kerI[j-1] = oldval;
                    oldval = newval;
                }
            }

            for( i = 0; i < order; i++ )
            {
                oldval = -kerI[0];
                for( j = 1; j <= ksize; j++ )
                {
                    newval = kerI[j-1] - kerI[j];
                    kerI[j-1] = oldval;
                    oldval = newval;
                }
            }
        }

        Mat temp(kernel->rows, kernel->cols, CV_32S, &kerI[0]);
        double scale = !normalize ? 1. : 1./(1 << (ksize-order-1));
        temp.convertTo(*kernel, ktype, scale);
    }
}

}

void cv::getDerivKernels( OutputArray kx, OutputArray ky, int dx, int dy,
                          int ksize, bool normalize, int ktype )
{
    if( ksize <= 0 )
        getScharrKernels( kx, ky, dx, dy, normalize, ktype );
    else
        getSobelKernels( kx, ky, dx, dy, ksize, normalize, ktype );
}


cv::Ptr<cv::FilterEngine> cv::createDerivFilter(int srcType, int dstType,
                                                int dx, int dy, int ksize, int borderType )
{
    Mat kx, ky;
    getDerivKernels( kx, ky, dx, dy, ksize, false, CV_32F );
    return createSeparableLinearFilter(srcType, dstType,
        kx, ky, Point(-1,-1), 0, borderType );
}

#if defined (HAVE_IPP) && (IPP_VERSION_MAJOR >= 7)

namespace cv
{

static bool IPPDerivScharr(const Mat& src, Mat& dst, int ddepth, int dx, int dy, double scale)
{
   int bufSize = 0;
   cv::AutoBuffer<char> buffer;
   IppiSize roi = ippiSize(src.cols, src.rows);

   if( ddepth < 0 )
     ddepth = src.depth();

   dst.create( src.size(), CV_MAKETYPE(ddepth, src.channels()) );

   switch(src.type())
   {
      case CV_8U:
         {
            if(scale != 1)
                return false;

            switch(dst.type())
            {
               case CV_16S:
               {
                  if((dx == 1) && (dy == 0))
                  {
                     ippiFilterScharrVertGetBufferSize_8u16s_C1R(roi,&bufSize);
                     buffer.allocate(bufSize);

                     ippiFilterScharrVertBorder_8u16s_C1R((const Ipp8u*)src.data, src.step,
                        (Ipp16s*)dst.data, dst.step, roi, ippBorderRepl, 0, (Ipp8u*)(char*)buffer);

                     return true;
                  }

                  if((dx == 0) && (dy == 1))
                  {
                     ippiFilterScharrHorizGetBufferSize_8u16s_C1R(roi,&bufSize);
                     buffer.allocate(bufSize);

                     ippiFilterScharrHorizBorder_8u16s_C1R((const Ipp8u*)src.data, src.step,
                        (Ipp16s*)dst.data, dst.step, roi, ippBorderRepl, 0, (Ipp8u*)(char*)buffer);

                     return true;
                  }
               }

               default:
                  return false;
            }
         }

      case CV_32F:
         {
            switch(dst.type())
            {
               case CV_32F:
               if((dx == 1) && (dy == 0))
               {
                  ippiFilterScharrVertGetBufferSize_32f_C1R(ippiSize(src.cols, src.rows),&bufSize);
                  buffer.allocate(bufSize);

                  ippiFilterScharrVertBorder_32f_C1R((const Ipp32f*)src.data, src.step,
                     (Ipp32f*)dst.data, dst.step, ippiSize(src.cols, src.rows),
                                            ippBorderRepl, 0, (Ipp8u*)(char*)buffer);
                  if(scale != 1)
                     \* IPP is fast, so MulC produce very little perf degradation *\
                     ippiMulC_32f_C1IR((Ipp32f)scale,(Ipp32f*)dst.data,dst.step,ippiSize(dst.cols*dst.channels(),dst.rows));

                  return true;
               }

               if((dx == 0) && (dy == 1))
               {
                  ippiFilterScharrHorizGetBufferSize_32f_C1R(ippiSize(src.cols, src.rows),&bufSize);
                  buffer.allocate(bufSize);

                  ippiFilterScharrHorizBorder_32f_C1R((const Ipp32f*)src.data, src.step,
                     (Ipp32f*)dst.data, dst.step, ippiSize(src.cols, src.rows),
                                            ippBorderRepl, 0, (Ipp8u*)(char*)buffer);
                  if(scale != 1)
                     ippiMulC_32f_C1IR((Ipp32f)scale,(Ipp32f *)dst.data,dst.step,ippiSize(dst.cols*dst.channels(),dst.rows));

                  return true;
               }

               default:
                  return false;
            }
         }

      default:
         return false;
   }
}


static bool IPPDeriv(const Mat& src, Mat& dst, int ddepth, int dx, int dy, int ksize, double scale)
{
   int bufSize = 0;
   cv::AutoBuffer<char> buffer;

   if(ksize == 3 || ksize == 5)
   {
      if( ddepth < 0 )
          ddepth = src.depth();

      if(src.type() == CV_8U && dst.type() == CV_16S && scale == 1)
      {
         if((dx == 1) && (dy == 0))
         {
            ippiFilterSobelNegVertGetBufferSize_8u16s_C1R(ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),&bufSize);
            buffer.allocate(bufSize);

            ippiFilterSobelNegVertBorder_8u16s_C1R((const Ipp8u*)src.data, src.step,
               (Ipp16s*)dst.data, dst.step, ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),
                                      ippBorderRepl, 0, (Ipp8u*)(char*)buffer);
            return true;
         }

         if((dx == 0) && (dy == 1))
         {
            ippiFilterSobelHorizGetBufferSize_8u16s_C1R(ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),&bufSize);
            buffer.allocate(bufSize);

            ippiFilterSobelHorizBorder_8u16s_C1R((const Ipp8u*)src.data, src.step,
               (Ipp16s*)dst.data, dst.step, ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),
                                      ippBorderRepl, 0, (Ipp8u*)(char*)buffer);

            return true;
         }

         if((dx == 2) && (dy == 0))
         {
            ippiFilterSobelVertSecondGetBufferSize_8u16s_C1R(ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),&bufSize);
            buffer.allocate(bufSize);

            ippiFilterSobelVertSecondBorder_8u16s_C1R((const Ipp8u*)src.data, src.step,
               (Ipp16s*)dst.data, dst.step, ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),
                                      ippBorderRepl, 0, (Ipp8u*)(char*)buffer);

            return true;
         }

         if((dx == 0) && (dy == 2))
         {
            ippiFilterSobelHorizSecondGetBufferSize_8u16s_C1R(ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),&bufSize);
            buffer.allocate(bufSize);

            ippiFilterSobelHorizSecondBorder_8u16s_C1R((const Ipp8u*)src.data, src.step,
               (Ipp16s*)dst.data, dst.step, ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),
                                      ippBorderRepl, 0, (Ipp8u*)(char*)buffer);

            return true;
         }
      }

      if(src.type() == CV_32F && dst.type() == CV_32F)
      {
         if((dx == 1) && (dy == 0))
         {
            ippiFilterSobelNegVertGetBufferSize_32f_C1R(ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),&bufSize);
            buffer.allocate(bufSize);

            ippiFilterSobelNegVertBorder_32f_C1R((const Ipp32f*)src.data, src.step,
               (Ipp32f*)dst.data, dst.step, ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),
                                      ippBorderRepl, 0, (Ipp8u*)(char*)buffer);
            if(scale != 1)
               ippiMulC_32f_C1IR((Ipp32f)scale,(Ipp32f *)dst.data,dst.step,ippiSize(dst.cols*dst.channels(),dst.rows));

            return true;
         }

         if((dx == 0) && (dy == 1))
         {
            ippiFilterSobelHorizGetBufferSize_32f_C1R(ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),&bufSize);
            buffer.allocate(bufSize);

            ippiFilterSobelHorizBorder_32f_C1R((const Ipp32f*)src.data, src.step,
               (Ipp32f*)dst.data, dst.step, ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),
                                      ippBorderRepl, 0, (Ipp8u*)(char*)buffer);
            if(scale != 1)
               ippiMulC_32f_C1IR((Ipp32f)scale,(Ipp32f *)dst.data,dst.step,ippiSize(dst.cols*dst.channels(),dst.rows));

            return true;
         }

         if((dx == 2) && (dy == 0))
         {
            ippiFilterSobelVertSecondGetBufferSize_32f_C1R(ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),&bufSize);
            buffer.allocate(bufSize);

            ippiFilterSobelVertSecondBorder_32f_C1R((const Ipp32f*)src.data, src.step,
               (Ipp32f*)dst.data, dst.step, ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),
                                      ippBorderRepl, 0, (Ipp8u*)(char*)buffer);
            if(scale != 1)
               ippiMulC_32f_C1IR((Ipp32f)scale,(Ipp32f *)dst.data,dst.step,ippiSize(dst.cols*dst.channels(),dst.rows));

            return true;
         }

         if((dx == 0) && (dy == 2))
         {
            ippiFilterSobelHorizSecondGetBufferSize_32f_C1R(ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),&bufSize);
            buffer.allocate(bufSize);

            ippiFilterSobelHorizSecondBorder_32f_C1R((const Ipp32f*)src.data, src.step,
               (Ipp32f*)dst.data, dst.step, ippiSize(src.cols, src.rows), (IppiMaskSize)(ksize*10+ksize),
                                      ippBorderRepl, 0, (Ipp8u*)(char*)buffer);
            if(scale != 1)
               ippiMulC_32f_C1IR((Ipp32f)scale,(Ipp32f *)dst.data,dst.step,ippiSize(dst.cols*dst.channels(),dst.rows));

            return true;
         }
      }
   }

   if(ksize <= 0)
      return IPPDerivScharr(src, dst, ddepth, dx, dy, scale);

   return false;
}

}

#endif

void cv::Sobel( InputArray _src, OutputArray _dst, int ddepth, int dx, int dy,
                int ksize, double scale, double delta, int borderType )
{
    Mat src = _src.getMat();
    if (ddepth < 0)
        ddepth = src.depth();
    _dst.create( src.size(), CV_MAKETYPE(ddepth, src.channels()) );
    Mat dst = _dst.getMat();

#ifdef HAVE_TEGRA_OPTIMIZATION
    if (scale == 1.0 && delta == 0)
    {
        if (ksize == 3 && tegra::sobel3x3(src, dst, dx, dy, borderType))
            return;
        if (ksize == -1 && tegra::scharr(src, dst, dx, dy, borderType))
            return;
    }
#endif

#if defined (HAVE_IPP) && (IPP_VERSION_MAJOR >= 7)
    if(dx < 3 && dy < 3 && src.channels() == 1 && borderType == 1)
    {
        if(IPPDeriv(src, dst, ddepth, dx, dy, ksize,scale))
            return;
    }
#endif
    int ktype = std::max(CV_32F, std::max(ddepth, src.depth()));

    Mat kx, ky;
    getDerivKernels( kx, ky, dx, dy, ksize, false, ktype );
    if( scale != 1 )
    {
        // usually the smoothing part is the slowest to compute,
        // so try to scale it instead of the faster differenciating part
        if( dx == 0 )
            kx *= scale;
        else
            ky *= scale;
    }
    sepFilter2D( src, dst, ddepth, kx, ky, Point(-1,-1), delta, borderType );
}


void cv::Scharr( InputArray _src, OutputArray _dst, int ddepth, int dx, int dy,
                 double scale, double delta, int borderType )
{
    Mat src = _src.getMat();
    if (ddepth < 0)
        ddepth = src.depth();
    _dst.create( src.size(), CV_MAKETYPE(ddepth, src.channels()) );
    Mat dst = _dst.getMat();

#ifdef HAVE_TEGRA_OPTIMIZATION
    if (scale == 1.0 && delta == 0)
        if (tegra::scharr(src, dst, dx, dy, borderType))
            return;
#endif

#if defined (HAVE_IPP) && (IPP_VERSION_MAJOR >= 7)
    if(dx < 2 && dy < 2 && src.channels() == 1 && borderType == 1)
    {
        if(IPPDerivScharr(src, dst, ddepth, dx, dy, scale))
            return;
    }
#endif
    int ktype = std::max(CV_32F, std::max(ddepth, src.depth()));

    Mat kx, ky;
    getScharrKernels( kx, ky, dx, dy, false, ktype );
    if( scale != 1 )
    {
        // usually the smoothing part is the slowest to compute,
        // so try to scale it instead of the faster differenciating part
        if( dx == 0 )
            kx *= scale;
        else
            ky *= scale;
    }
    sepFilter2D( src, dst, ddepth, kx, ky, Point(-1,-1), delta, borderType );
}


void cv::Laplacian( InputArray _src, OutputArray _dst, int ddepth, int ksize,
                    double scale, double delta, int borderType )
{
    Mat src = _src.getMat();
    if (ddepth < 0)
        ddepth = src.depth();
    _dst.create( src.size(), CV_MAKETYPE(ddepth, src.channels()) );
    Mat dst = _dst.getMat();

#ifdef HAVE_TEGRA_OPTIMIZATION
    if (scale == 1.0 && delta == 0)
    {
        if (ksize == 1 && tegra::laplace1(src, dst, borderType))
            return;
        if (ksize == 3 && tegra::laplace3(src, dst, borderType))
            return;
        if (ksize == 5 && tegra::laplace5(src, dst, borderType))
            return;
    }
#endif

    if( ksize == 1 || ksize == 3 )
    {
        float K[2][9] =
        {{0, 1, 0, 1, -4, 1, 0, 1, 0},
         {2, 0, 2, 0, -8, 0, 2, 0, 2}};
        Mat kernel(3, 3, CV_32F, K[ksize == 3]);
        if( scale != 1 )
            kernel *= scale;
        filter2D( src, dst, ddepth, kernel, Point(-1,-1), delta, borderType );
    }
    else
    {
        const size_t STRIPE_SIZE = 1 << 14;

        int depth = src.depth();
        int ktype = std::max(CV_32F, std::max(ddepth, depth));
        int wdepth = depth == CV_8U && ksize <= 5 ? CV_16S : depth <= CV_32F ? CV_32F : CV_64F;
        int wtype = CV_MAKETYPE(wdepth, src.channels());
        Mat kd, ks;
        getSobelKernels( kd, ks, 2, 0, ksize, false, ktype );
        if( ddepth < 0 )
            ddepth = src.depth();
        int dtype = CV_MAKETYPE(ddepth, src.channels());

        int dy0 = std::min(std::max((int)(STRIPE_SIZE/(getElemSize(src.type())*src.cols)), 1), src.rows);
        Ptr<FilterEngine> fx = createSeparableLinearFilter(src.type(),
            wtype, kd, ks, Point(-1,-1), 0, borderType, borderType, Scalar() );
        Ptr<FilterEngine> fy = createSeparableLinearFilter(src.type(),
            wtype, ks, kd, Point(-1,-1), 0, borderType, borderType, Scalar() );

        int y = fx->start(src), dsty = 0, dy = 0;
        fy->start(src);
        const uchar* sptr = src.data + y*src.step;

        Mat d2x( dy0 + kd.rows - 1, src.cols, wtype );
        Mat d2y( dy0 + kd.rows - 1, src.cols, wtype );

        for( ; dsty < src.rows; sptr += dy0*src.step, dsty += dy )
        {
            fx->proceed( sptr, (int)src.step, dy0, d2x.data, (int)d2x.step );
            dy = fy->proceed( sptr, (int)src.step, dy0, d2y.data, (int)d2y.step );
            if( dy > 0 )
            {
                Mat dstripe = dst.rowRange(dsty, dsty + dy);
                d2x.rows = d2y.rows = dy; // modify the headers, which should work
                d2x += d2y;
                d2x.convertTo( dstripe, dtype, scale, delta );
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

CV_IMPL void
cvSobel( const void* srcarr, void* dstarr, int dx, int dy, int aperture_size )
{
    cv::Mat src = cv::cvarrToMat(srcarr), dst = cv::cvarrToMat(dstarr);

    CV_Assert( src.size() == dst.size() && src.channels() == dst.channels() );

    cv::Sobel( src, dst, dst.depth(), dx, dy, aperture_size, 1, 0, cv::BORDER_REPLICATE );
    if( CV_IS_IMAGE(srcarr) && ((IplImage*)srcarr)->origin && dy % 2 != 0 )
        dst *= -1;
}


CV_IMPL void
cvLaplace( const void* srcarr, void* dstarr, int aperture_size )
{
    cv::Mat src = cv::cvarrToMat(srcarr), dst = cv::cvarrToMat(dstarr);

    CV_Assert( src.size() == dst.size() && src.channels() == dst.channels() );

    cv::Laplacian( src, dst, dst.depth(), aperture_size, 1, 0, cv::BORDER_REPLICATE );
}


























//void cv::Scharr(InputArray _src, OutputArray _dst, int ddepth, int dx, int dy, double scale, double delta, int borderType)
    / *
    Mat src = _src.getMat();
    if (ddepth < 0)
        ddepth = src.depth();
    _dst.create( src.size(), CV_MAKETYPE(ddepth, src.channels()) );
    Mat dst = _dst.getMat();
    * /
    cv::Mat src = ((cv::InputArray)gMat).getMat();
    if (ddepth < 0)
        ddepth = src.depth();
    ((cv::OutputArray)_dst).create(src.size(), CV_MAKETYPE(ddepth, src.channels()));
    cv::Mat dst = ((cv::OutputArray)_dst).getMat();

    int ktype = std::max(CV_32F, std::max(ddepth, src.depth()));

    cv::Mat kx, ky;
    //getScharrKernels(_kx, _ky, dx, dy, false, ktype);
    //static void getScharrKernels(OutputArray _kx, OutputArray _ky, int dx, int dy, bool normalize, int ktype) {
    //const int ksize = 3;

    CV_Assert(ktype == CV_32F || ktype == CV_64F);
    ((cv::OutputArray)kx).create(ksize, 1, ktype, -1, true);
    ((cv::OutputArray)ky).create(ksize, 1, ktype, -1, true);
    cv::Mat _kx = ((cv::InputArray)kx).getMat();
    cv::Mat _ky = ((cv::InputArray)ky).getMat();

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
        double scale = !true || order == 1 ? 1. : 1./32;
        temp.convertTo(*kernel, ktype, scale);
    }
    //}
    if(gain != 1) {
        // usually the smoothing part is the slowest to compute,
        // so try to scale it instead of the faster differenciating part
        if(dx == 0)
            kx *= gain;
        else
            ky *= gain;
    }
    cv::sepFilter2D(src, dst, ddepth, kx, ky, cv::Point(-1,-1), offset, borderType);
*/

void MainWindow::calculerGradientPrewitt (QImage& argbImage, QString titre, TypePrewitt type, double gain, double offset, int borderType) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    /*cv::GaussianBlur(bgrMat, bgrMat, cv::Size(3,3), 0, 0, borderType);
    cv::Mat gMat;
    cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);



    cv::Mat _dst;
    int dx = 1;
    int dy = 0;
    Prewitt(gMat, _dst, CV_16S, dx, dy, gain*25, offset, borderType);



    cv::convertScaleAbs(_dst, bgrMat);
    //normalize(const Mat& src, Mat& dst, double alpha=1, double beta=0, int normType=NORM_L2, int rtype=-1, const Mat& mask=Mat())
    if(type==PREWITT_X) cv::normalize(bgrMat, bgrMat, 0, 255, CV_MINMAX, -1, cv::Mat());
    cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);*/






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
        //cv::Sobel (gMat, dst, CV_16S, dx, dy, ksize, gain, offset, borderType);
        Prewitt(gMat, dst, CV_16S, dx, dy, gain*25, offset, borderType);
        cv::convertScaleAbs(dst, bgrMat);
        //cv::normalize(bgrMat, bgrMat, 0, 255, CV_MINMAX, -1, cv::Mat());
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
        //cv::Sobel (gMat, dst_x, CV_16S, dx, dy, ksize, gain, offset, borderType);
        Prewitt(gMat, dst_x, CV_16S, dx, dy, gain, offset, borderType);
        dst_x.convertTo(x, CV_32F, 1.f, 0);
        ///d/dy
        dx = 0;
        dy = 1;
        //cv::Sobel (gMat, dst_y, CV_16S, dx, dy, ksize, gain, offset, borderType);
        Prewitt(gMat, dst_y, CV_16S, dx, dy, gain, offset, borderType);
        dst_y.convertTo(y, CV_32F, 1.f, 0);
        //cv::convertScaleAbs(dst_x, dst_x);
        //cv::convertScaleAbs(dst_y, dst_y);
        //cv::addWeighted (dst_x, 0.5, dst_y, 0.5, 0, dst_total);
        //cv::imshow("Manhattan", dst_total);
        x = x.mul(x);
        y = y.mul(y);
        s = x + y;
        cv::sqrt(s, dst_total);
        cv::normalize(dst_total, dst_total, 0, 1, CV_MINMAX);
        dst_total.convertTo(dst_total, CV_8U, 255, 0);
        //cv::imshow("Euclidean", dst_total);
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



void MainWindow::on_actionOuvrir_triggered () {
    QFileDialog fileDialog;
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    QString nomFichier = fileDialog.getOpenFileName(this, tr("Ouvrir Image"), tr(DOSSIER_DEFAUT_OUVERTURE_IMAGES), tr(PATTERN_OUVERTURE_IMAGES_QT_ET_OPENCV));
    if (nomFichier.isEmpty())
        return;
    ouvrirImage(nomFichier.toStdString ().data ());
}

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

void MainWindow::on_actionManuelDouble_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherSeuillageManuelDouble (label);
}

void MainWindow::on_actionSeuillageParHysteresis_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherSeuillageParHysteresis (label);
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

void MainWindow::on_actionGainOffsetHistogramme_triggered () {
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;

    QImage image = label->pixmap()->toImage();
    int seuil1, seuil2;
    bool ok;
    IntIntDialog d(this, QString("*Calibration d'Histogramme"), QString("Min (entre 0 et 255): "), 80, 0, 255, 1, QString("Max (entre 0 et 255): "), 240, 0, 255, 1);
    d.run(seuil1, seuil2, ok);
    if (!ok) return;
    this->statusBar()->showMessage(tr("*Calibration d'Histogramme(%1;%2): ").arg(seuil1).arg(seuil2));
    QString titre = QString("*Calibration d'Histogramme(%1;%2): ").arg(seuil1).arg(seuil2) + windowTitle[qHash(label)];
    QImage argbImage = image;
    double valeurMin = seuil1;
    double valeurMax = seuil2;

    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);
    cv::normalize(bgrMat, bgrMat, valeurMin, valeurMax, CV_MINMAX);
    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

