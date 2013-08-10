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
    ui->actionSoustraction->setEnabled(true);
    ui->actionCombinaison->setEnabled(true);
    ui->actionNOT->setEnabled(true);
    ui->actionPlanBinaire->setEnabled(true);
    ui->actionQuantification->setEnabled(true);
    ui->actionBruitUniforme->setEnabled(true);
    ui->actionBruitPoivreEtSel->setEnabled(true);
    ui->actionUniforme->setEnabled(true);
    ui->actionRampe->setEnabled(true);

    //menu filtrage
    ui->actionMoyenneur3x3->setEnabled(true);
    ui->actionMoyenneurNxN->setEnabled(true);
    ui->actionLaplacien->setEnabled(true);
    ui->actionMedian->setEnabled(true);
    ui->actionFFT->setEnabled(true);

    ui->actionMoyenneurNxN->setText(tr("Moyenneur nxn"));
    ui->actionMoyenneurNxN->setIconText(tr("Moyenneur nxn"));
    ui->actionMoyenneurNxN->setToolTip(tr("Moyenneur nxn"));

    //menu segmentation
    ui->actionManuelSimple->setEnabled(true);
    ui->actionSeuillageParHysteresis->setEnabled(true);
    ui->actionNormeSobel->setEnabled(true);
    ui->actionGradientXSobel->setEnabled(true);
    ui->actionGradientYSobel->setEnabled(true);
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
        for( int i = 1; i < histSize; i++ ) {
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
        for( int i = 1; i < histSize; i++ ) {
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

    if (argbImage.isGrayscale()) {
        cv::Mat gMat;
        cv::cvtColor (bgrMat, gMat, CV_BGR2GRAY);
        cv::Mat result;
        equalizeHist (gMat, result);
        cv::cvtColor (result, bgrMat, CV_GRAY2BGR);
    } else
        return;

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
        for( it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
            (*it)[0] = lookup[(*it)[0]];
            (*it)[1] = lookup[(*it)[1]];
            (*it)[2] = lookup[(*it)[2]];
        }
    }*/
    cv::MatIterator_<cv::Vec3b> it, end;
    for( it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
        (*it)[0] = lookup[(*it)[0]];
        (*it)[1] = lookup[(*it)[1]];
        (*it)[2] = lookup[(*it)[2]];
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

void MainWindow::afficherNOT (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("NOT: ") + windowTitle[qHash(label)];
    calculerNOT(image, titre);
}

void MainWindow::calculerNOT (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::MatIterator_<cv::Vec3b> it, end;
    for( it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
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
    for( it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
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
    for( it = bgrMat.begin<cv::Vec3b>(), end = bgrMat.end<cv::Vec3b>(); it != end; ++it) {
        (*it)[0] = (*it)[0] & masque;
        (*it)[1] = (*it)[1] & masque;
        (*it)[2] = (*it)[2] & masque;
    }

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
    for( i = 0; i < nRows; ++i)
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

    cv::blur (bgrMat, bgrMat, cv::Size(3,3), anchor, borderType);

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
    int N = QInputDialog::getInt(this, tr("Moyenneur nxn"), tr("N: "), 3, 3, 31, 1, &ok, 0);
    if (!ok) return;
    this->statusBar()->showMessage(tr("N = %1").arg(N));
    QString titre = QString("Moyenneur %1x%2: ").arg(N).arg(N) + windowTitle[qHash(label)];
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
    /*bool ok;
    int seuil = QInputDialog::getInt(this, tr("Seuillage Simple"), tr("Seuil (entre 0 et 255): "), 127, 0, 255, 1, &ok, 0);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Seuil = %1").arg(seuil));
    QString titre = QString("Seuillage(s=%1): ").arg(seuil) + windowTitle[qHash(label)];*/
    QString titre = QString("Laplacien: ") + windowTitle[qHash(label)];
    calculerLaplacien(image, titre, 3, 1, 0, BORDER_TYPE);
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
    this->statusBar()->showMessage(tr("Seuil = %1").arg(seuil));
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
    /*QDialog d(this, Qt::WindowOkButtonHint | Qt::WindowCancelButtonHint);
    //QAction a(QString("blah"),d);
    //d.addAction(a);
    d.show();//d.exec();
    int x = d.result();*/
    /*
     *int 	getInt ( QWidget * parent, const QString & title, const QString & label, int value = 0, int min = -2147483647, int max = 2147483647, int step = 1, bool * ok = 0, Qt::WindowFlags flags = 0 )
     bool ok;
     int i = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
                                  tr("Percentage:"), 25, 0, 100, 1, &ok, 0);
     if (ok)
         integerLabel->setText(tr("%1%").arg(i));
     */
    bool ok;
    int seuil = QInputDialog::getInt(this, tr("Seuillage Double"), tr("Seuil (entre 0 et 255): "), 127, 0, 255, 1, &ok, 0);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Seuil = %1").arg(seuil));
    QString titre = QString("Seuillage(%1): ").arg(seuil) + windowTitle[qHash(label)];
    calculerSeuillageManuelDouble(image, titre, seuil, 255);
}

void MainWindow::calculerSeuillageManuelDouble (QImage& argbImage, QString titre, double seuil, double maxval) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

/*
 *seuillage :
cv::Mat thresholded;
cv::threshold(image, thresholded, 60, 255, cv::THRESH_BINARY);
cv::imwrite ("binary.bmp", thresholded);
*/

/*
 *cv::adaptiveThreshold(src,dst,double maxval,adaptativeMethod,thresholdType,int blockSize,double C)
 *cv::blur(src,dst,Size ksize,Point anchor = (-1,-1),borderType=BORDER_DEFAULT)
 *cv::Canny(src,dst_edges,double  threshold1,double threshold2,int apertureSize=3,bool L2gradient=false)
 *cv::CLAHE
 *cv::createCLAHE()
 *cv::createDerivFilter()
 *cv::createGaussianFilter()
 *cv::createHanningWindow()
 *cv::createLinearFilter()
 *cv::createMorphologyFilter()
 *cv::createSeparableLinearFilter()
 *cv::dct()
 *cv::dft()
 *cv::erode(src,dst,i_kernel,Point anchor = (-1,-1),int iterations=1,border,const Scalar& borderValue=morphologyDefaultBorderValue)
 *cv::meanStdDev(src, mean, stddev, mask=noArray())
 *cv::medianBlur(src, dst, int ksize)
 *cv::Mahalanobis(src1, src2, icovar)
 *cv::Mahalonobis(src1, src2, icovar)
 *cv::Laplacian(src,dst,ddepth,int ksize=3,double scale=1,double delta=0,borderType=BORDER_DEFAULT)
 *cv::Scharr(src,dst,ddepth,int dx,int dy,int ksize=3,double scale=1,double delta=0,borderType=BORDER_DEFAULT)
 *cv::Sobel(src,dst,ddepth,int dx=0 ou 1,int dy=0 ou 1,int ksize=3,double scale=1,double delta=0,borderType=BORDER_DEFAULT)
 */

    /*if (argbImage.isGrayscale()) {
        cv::Mat gMat;
        cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
        cv::Mat result (gMat.rows, gMat.cols, CV_8U);
        cv::threshold(gMat, result, seuil, maxval, cv::THRESH_BINARY);
        cv::cvtColor(result, bgrMat, CV_GRAY2BGR);
    } else {
        cv::threshold(bgrMat, bgrMat, seuil, maxval, cv::THRESH_BINARY);
    }*/

    cv::threshold(bgrMat, bgrMat, seuil, maxval, cv::THRESH_BINARY);
    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherSeuillageParHysteresis (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    /*bool ok;
    int seuil = QInputDialog::getInt(this, tr("Seuillage Simple"), tr("Seuil (entre 0 et 255): "), 127, 0, 255, 1, &ok, 0);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Seuil = %1").arg(seuil));*/
    QString titre = QString("Seuillage par Hystérésis: ") + windowTitle[qHash(label)];
    calculerSeuillageParHysteresis (image, titre, 80, 3 * 30, 3, true);///ratio seuilHaut/seuilBas preferablement entre 3:1 et 2:1
}

void MainWindow::calculerSeuillageParHysteresis (QImage& argbImage, QString titre, int seuilBas, int seuilHaut, int ksize, bool utiliserNormeL2) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);

    cv::Mat gMat;
    cv::cvtColor (bgrMat, gMat, CV_BGR2GRAY);
    cv::blur (gMat, gMat, cv::Size(3,3), cv::Point(-1,-1), BORDER_TYPE);
    //cv::GaussianBlur (bgrMat, gMat, cv::Size(3,3), 0, 0, BORDER_TYPE);
    cv::Mat edges;
    cv::Canny (gMat, edges, seuilBas, seuilHaut, ksize, utiliserNormeL2);
    cv::Mat dst (bgrMat.size(), bgrMat.type(), cv::Scalar::all(0));
    bgrMat.copyTo (dst, edges);

    cvMatToQImage(dst, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherGradientSobel (QLabel* label, TypeSobel type) {
    QImage image = label->pixmap()->toImage();
    /*bool ok;
    int seuil = QInputDialog::getInt(this, tr("Seuillage Simple"), tr("Seuil (entre 0 et 255): "), 127, 0, 255, 1, &ok, 0);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Seuil = %1").arg(seuil));
    QString titre = QString("Seuillage(%1): ").arg(seuil) + windowTitle[qHash(label)];*/
    QString titre = QString("Sobel Gradient %1: ").arg(type == SOBEL_NORME ? "(Norme)" : type == SOBEL_X ? "X" : type == SOBEL_Y ? "Y" : "") + windowTitle[qHash(label)];
    calculerGradientSobel (image, titre, type, 3, 1, 0, BORDER_TYPE);
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
        cv::Mat dst_x, dst_y, abs_dst_x, abs_dst_y, dst_total;
        //DX
        dx = 1;
        dy = 0;
        cv::Sobel (gMat, dst_x, CV_16S, dx, dy, ksize, gain, offset, borderType);
        cv::convertScaleAbs(dst_x, abs_dst_x);
        //DY
        dx = 0;
        dy = 1;
        cv::Sobel (gMat, dst_y, CV_16S, dx, dy, ksize, gain, offset, borderType);
        cv::convertScaleAbs(dst_y, abs_dst_y);
        cv::addWeighted (abs_dst_x, 0.5, abs_dst_y, 0.5, 0, dst_total);
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

