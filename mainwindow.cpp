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
    //QLayout* layout = new QHBoxLayout;
    //this->centralWidget()->setLayout(layout);

    //ouvrirImage("../TCIMAG_ressources/lena.bmp");
    //ouvrirImage("../TCIMAG_ressources/lenaGray.bmp");
    //ouvrirImage("../TCIMAG_ressources/lena.jpg");
    //ouvrirImage("../TCIMAG_ressources/lena.jpeg");
    //ouvrirImage("../TCIMAG_ressources/lena.png");
    //ouvrirImage("../TCIMAG_ressources/lena.pgm");
    //ouvrirImage("../TCIMAG_ressources/lena.ppm");
    //ouvrirImage("../TCIMAG_ressources/lena.tiff");

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
    ui->actionNegatif->setEnabled(true);
    ui->actionAddition->setEnabled(true);
    ui->actionSoustraction->setEnabled(true);

    //menu filtrage
    ui->actionLaplacien->setEnabled(true);

    //menu segmentation
    ui->actionManuelSimple->setEnabled(true);
    ui->actionSeuillageParHysteresis->setEnabled(true);
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
        return QWidget::eventFilter(watched, e);
    //} else if (e->type() == QEvent::WindowDeactivate) {
    //    std::cerr << "win deact: " << typeid(*watched).name() << std::endl;
    //    return QWidget::eventFilter(watched, e);
    } else if (e->type() == QEvent::Close) {
        std::cerr << "closed: " << typeid(*watched).name() << std::endl;
        return QWidget::eventFilter(watched, e);
    }
    return QWidget::eventFilter(watched, e);
}

/*const cv::Mat MainWindow::qtRGBToCvBGR (const QImage& argbImage, enum QImage::Format format = QImage::Format_RGB888) {
    //if (argbImage.isNull())
    return cv::Mat();
    / *QImage rgbImage = argbImage.convertToFormat(format, Qt::ColorOnly);
    ////cv::Mat (int _rows, int _cols, int _type, void* _data, size_t _step=AUTO_STEP);
    cv::Mat matRGB(rgbImage.width(), rgbImage.height(), CV_8UC3, rgbImage.bits(), rgbImage.bytesPerLine());
    cv::Mat* matBGR = new cv::Mat(matRGB);
    cv::cvtColor(matRGB, *matBGR, CV_RGB2BGR);
    return *matBGR;* /
}*/

/*const QImage MainWindow::cvBGRToQtRGB (const cv::Mat& bgrImage, enum QImage::Format format = QImage::Format_RGB888) {
    //if (!bgrImage.data)
    return QImage();
    / *cv::Mat* matRGB = new cv::Mat(bgrImage);
    cv::cvtColor(bgrImage, *matRGB, CV_BGR2RGB);
    ////QImage::QImage ( const uchar * data, int width, int height, int bytesPerLine, Format format )
    QImage rgbImg = QImage((uchar*)matRGB->data, matRGB->cols, matRGB->rows, matRGB->step, format);
    return rgbImg;* /
}*/

/*void QImageTocvMat(QImage* in, cv::Mat* out) {
    *in = in->convertToFormat(QImage::Format_RGB888, Qt::ColorOnly);
    ////cv::Mat (int _rows, int _cols, int _type, void* _data, size_t _step=AUTO_STEP);
    cv::Mat matRGB(in->width(), in->height(), CV_8UC3, in->bits(), in->bytesPerLine());
    cv::cvtColor(matRGB, *out, CV_RGB2BGR);
}

void cvMatToQImage(cv::Mat* in, QImage* out) {
    cv::cvtColor(*in, *in, CV_BGR2RGB);
    ////QImage::QImage ( const uchar * data, int width, int height, int bytesPerLine, Format format )
    *out = QImage((uchar*)in->data, in->cols, in->rows, in->step, QImage::Format_RGB888);
}*/

void QImageTocvMat(const QImage& in, cv::Mat& out) {
    QImage img = in.convertToFormat(QImage::Format_RGB888, Qt::ColorOnly);
    ////cv::Mat (int _rows, int _cols, int _type, void* _data, size_t _step=AUTO_STEP);
    cv::Mat matRGB(img.width(), img.height(), CV_8UC3, img.bits(), img.bytesPerLine());
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
    cvMatToQImage(loadImg, rgbImg);//cvMatToQImage(&loadImg, &rgbImg);
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
    //creerFenetre (QPixmap::fromImage (loadImg), QDir (tr (nomFichier)).absolutePath());
    ////todo: utiliser le path complet pour le titre?

    //this->centralWidget()->layout()->addWidget(subWindow);
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

    //this->centralWidget()->layout()->addWidget(subWindow);
}

void MainWindow::scaleImage (double factor, QScrollArea* paneau) {
    ////
    ////QScrollArea -> QWidget -> QLabel
    ////
    QLabel* image = this->getLabelInArea(paneau);//(QLabel*) paneau->children().first()->children().first();
    QSize actuelle = image->pixmap()->size();
    if (!this->scaleFactor.contains(qHash(image)))
        return;
    double scaleFactor = this->scaleFactor[qHash(image)] * factor;
    this->scaleFactor[qHash(image)] = scaleFactor;

    image->setFixedSize(scaleFactor * actuelle);

    adjustScrollBar (scaleFactor, paneau->horizontalScrollBar());
    adjustScrollBar (scaleFactor, paneau->verticalScrollBar());

    updateZoomActions(image);
}

void MainWindow::adjustScrollBar (double factor, QScrollBar* scrollBar) {
    scrollBar->setValue (int (factor * scrollBar->value () + (factor - 1) * scrollBar->pageStep () / 2));
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
    QString titre = QString("Histogramme pour : ") + windowTitle[qHash(label)];
    calculerHistogramme(image, titre);
}

void MainWindow::calculerHistogramme(QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);//QImageTocvMat(&argbImage, &bgrMat);

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

void MainWindow::afficherHistogrammeNegatif (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("! ") + windowTitle[qHash(label)];
    calculerHistogrammeNegatif(image, titre);
}

void MainWindow::calculerHistogrammeNegatif (QImage& argbImage, QString titre) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);//QImageTocvMat(&argbImage, &bgrMat);

/*
uchar lookup [256];
for(int i=0; i<256; i++)
  lookup[i]=255-i;

cv::Mat applyLookup(const cv::Mat& image, const cv::MatND& lookup) {
  cv::Mat result(image.rows, image.cols, CV_8U);
  cv::Mat_<uchar>::iterator itr = result.begin<uchar>();
  cv::Mat_<uchar>::const_iterator it = image.begin<uchar>();
  cv::Mat_<uchar>::const_iterator itend = image.end<uchar>();
  for(; it != itend; ++it, ++itr)
    *itr = lookup.at<uchar>(*it);
  return result;
}
*/

    uchar lookup [256];
    for(int i = 0; i < 256; i++) lookup[i] = 255 - i;
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
    } else {return;
        /*cv::Mat result (bgrMat.rows, bgrMat.cols, CV_8UC3);
        cv::Mat_<uchar>::iterator itr = result.begin<uchar>();
        cv::Mat_<uchar>::const_iterator it = bgrMat.begin<uchar>();
        cv::Mat_<uchar>::const_iterator itend = bgrMat.end<uchar>();
        for(; it != itend; ++it, ++itr)
            *itr = lookup[*it];
        bgrMat = result;*/
    }
    cvMatToQImage(bgrMat, argbImage);
    creerFenetre(QPixmap::fromImage(argbImage), titre);
}

void MainWindow::afficherAddition (QLabel* labelDroite, QLabel* labelGauche) {
    QImage imageDroite = labelDroite->pixmap()->toImage();
    QImage imageGauche = labelGauche->pixmap()->toImage();
    QString titre = windowTitle[qHash(labelDroite)] + QString(" + ") + windowTitle[qHash(labelGauche)];
    calculerAddition(imageDroite, imageGauche, titre);
}

void MainWindow::calculerAddition (QImage& argbImageGauche, QImage& argbImageDroite, QString titre) {
    cv::Mat bgrMatG;
    QImageTocvMat(argbImageGauche, bgrMatG);
    cv::Mat bgrMatD;
    QImageTocvMat(argbImageDroite, bgrMatD);
    /*
     double alpha = 0.5;
     Mat src1, src2, dst;
     addWeighted( src1, alpha, src2, 1 - alpha, 0.0, dst);
     */
    double alpha = 0.5;
    cv::Mat dst;
    cv::addWeighted (bgrMatG, alpha, bgrMatD, 1 - alpha, 0.0, dst, -1);
    QImage result;
    cvMatToQImage(dst, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

void MainWindow::afficherSoustraction (QLabel* labelDroite, QLabel* labelGauche) {
    QImage imageDroite = labelDroite->pixmap()->toImage();
    QImage imageGauche = labelGauche->pixmap()->toImage();
    QString titre = windowTitle[qHash(labelDroite)] + QString(" - ") + windowTitle[qHash(labelGauche)];
    calculerSoustraction(imageDroite, imageGauche, titre);
}

void MainWindow::calculerSoustraction (QImage& argbImageGauche, QImage& argbImageDroite, QString titre) {
    cv::Mat bgrMatG;
    QImageTocvMat(argbImageGauche, bgrMatG);
    cv::Mat bgrMatD;
    QImageTocvMat(argbImageDroite, bgrMatD);
    /*
     double alpha = 0.5;
     Mat src1, src2, dst;
     addWeighted( src1, alpha, src2, 1 - alpha, 0.0, dst);
     */
    double alpha = 0.5;
    cv::Mat dst;
    cv::addWeighted (bgrMatG, alpha, bgrMatD, -1 + alpha, 127, dst, -1);
    QImage result;
    cvMatToQImage(dst, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

//menu filtrage
void MainWindow::afficherLaplacien (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    /*bool ok;
    int seuil = QInputDialog::getInt(this, tr("Seuillage Simple"), tr("Seuil (entre 0 et 255): "), 127, 0, 255, 1, &ok);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Seuil = %1").arg(seuil));
    QString titre = QString("Seuillage(s=%1): ").arg(seuil) + windowTitle[qHash(label)];*/
    QString titre = QString("Laplacien: ") + windowTitle[qHash(label)];
    calculerLaplacien(image, titre, 3, 1, 0, BORDER_TYPE);
}

void MainWindow::calculerLaplacien (QImage& argbImage, QString titre, int ksize, double gain, double offset, uint borderType) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);
    /*
     *
    incl improc
    incl highgui
    incl stdlib
    incl stdio

    using namespace cv

    main () {
    Mat src, src_gray, dst, abs_dst;
    int kernel_size = 3;
    int scale = 1;//GAIN
    int delta = 0;//offset
    int ddepth = CV16S;//Assez pour qu'y'ait pas de debordement pour CV_8U
    winname
    int c;
    src = imread
    !src.data
    GaussianBlur(src, src, Size(3,3), 0, 0, BORDER_DEFAULT)
    cvtColor(src, src_gray, CV_RGB2GRAY);
    namedWindow winname
    Laplacian(src_gray, dst, ddepth, kernel_size, scale,...
    convertScaleAbs(dst, abs_dst);
    imshow winname
    }
     */
    cv::GaussianBlur(bgrMat, bgrMat, cv::Size(3,3), 0, 0, borderType);
    cv::Mat gMat;
    cv::cvtColor(bgrMat, gMat, CV_BGR2GRAY);
    cv::Mat dst;
    cv::Laplacian (gMat, dst, CV_16S, ksize, gain,offset, borderType);
    cv::convertScaleAbs(dst, bgrMat);
    cv::cvtColor(bgrMat, bgrMat, CV_GRAY2BGR);
    QImage result;
    cvMatToQImage(bgrMat, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

//menu segmentation
void MainWindow::afficherSeuillageManuelSimple (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    bool ok;
    int seuil = QInputDialog::getInt(this, tr("Seuillage Simple"), tr("Seuil (entre 0 et 255): "), 127, 0, 255, 1, &ok);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Seuil = %1").arg(seuil));
    QString titre = QString("Seuillage(s=%1): ").arg(seuil) + windowTitle[qHash(label)];
    calculerSeuillageManuelSimple (image, titre, seuil, 255);
}

void MainWindow::calculerSeuillageManuelSimple (QImage& argbImage, QString titre, double seuil, double maxval) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);
/*
 *seuillage :
cv::Mat thresholded;
cv::threshold(image, thresholded, 60, 255, cv::THRESH_BINARY);
cv::imwrite ("binary.bmp", thresholded);
*/
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
                                  tr("Percentage:"), 25, 0, 100, 1, &ok);
     if (ok)
         integerLabel->setText(tr("%1%").arg(i));
     */
    bool ok;
    int seuil = QInputDialog::getInt(this, tr("Seuillage Double"), tr("Seuil (entre 0 et 255): "), 127, 0, 255, 1, &ok);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Seuil = %1").arg(seuil));
    QString titre = QString("Seuillage(s=%1): ").arg(seuil) + windowTitle[qHash(label)];
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
    int seuil = QInputDialog::getInt(this, tr("Seuillage Simple"), tr("Seuil (entre 0 et 255): "), 127, 0, 255, 1, &ok);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Seuil = %1").arg(seuil));*/
    QString titre = QString("Seuillage par Hystérésis: ") + windowTitle[qHash(label)];
    calculerSeuillageParHysteresis (image, titre, 80, 3 * 30, 3, true);///ratio seuilHaut/seuilBas preferablement entre 3:1 et 2:1
}

void MainWindow::calculerSeuillageParHysteresis (QImage& argbImage, QString titre, int seuilBas, int seuilHaut, int ksize, bool utiliserNormeL2) {
    cv::Mat bgrMat;
    QImageTocvMat(argbImage, bgrMat);
    /*
  /// Load an image
  src = imread( argv[1] );

  if( !src.data )
    { return -1; }

  /// Create a matrix of the same type and size as src (for dst)
  dst.create( src.size(), src.type() );

  /// Convert the image to grayscale
  cvtColor( src, src_gray, COLOR_BGR2GRAY );

  /// Create a window
  namedWindow( window_name, WINDOW_AUTOSIZE );

  /// Create a Trackbar for user to enter threshold
  createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );

  /// Show the image
  CannyThreshold(0, 0);
    /// Reduce noise with a kernel 3x3
    blur( src_gray, detected_edges, Size(3,3) );

    /// Canny detector
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );

    /// Using Canny's output as a mask, we display our result
    dst = Scalar::all(0);

    src.copyTo( dst, detected_edges);
     */
    cv::Mat gMat;
    cv::cvtColor (bgrMat, gMat, CV_BGR2GRAY);
    cv::blur (gMat, gMat, cv::Size(3,3), cv::Point(-1,-1), BORDER_TYPE);
    //cv::GaussianBlur (bgrMat, gMat, cv::Size(3,3), 0, 0, BORDER_TYPE);
    cv::Mat edges;
    cv::Canny (gMat, edges, seuilBas, seuilHaut, ksize, utiliserNormeL2);
    cv::Mat dst (bgrMat.size(), bgrMat.type(), cv::Scalar::all(0));
    bgrMat.copyTo (dst, edges);
    //faire la somme des arcs et l'image de depart
    QImage result;
    cvMatToQImage(dst, result);
    creerFenetre(QPixmap::fromImage(result), titre);
}

void MainWindow::afficherGradientSobel (QLabel* label, TypeSobel type) {
    QImage image = label->pixmap()->toImage();
    /*bool ok;
    int seuil = QInputDialog::getInt(this, tr("Seuillage Simple"), tr("Seuil (entre 0 et 255): "), 127, 0, 255, 1, &ok);
    if (!ok) return;
    this->statusBar()->showMessage(tr("Seuil = %1").arg(seuil));
    QString titre = QString("Seuillage(s=%1): ").arg(seuil) + windowTitle[qHash(label)];*/
    QString titre = QString("Sobel Gradient %1: ").arg( type == SOBEL_X ? "X" : type == SOBEL_Y ? "Y" : "") + windowTitle[qHash(label)];
    calculerGradientSobel (image, titre, type, 3, 1, 0, BORDER_TYPE);
}

void MainWindow::calculerGradientSobel (QImage& argbImage, QString titre, TypeSobel type, int ksize, double gain, double offset, uint borderType) {
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
    }
    QImage result;
    cvMatToQImage(bgrMat, result);
    creerFenetre(QPixmap::fromImage(result), titre);
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
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QScrollArea* scrollArea = getFocusedArea();
    if (scrollArea == NULL)
        return;
    scaleImage(1/scaleFactor[qHash(getFocusedLabel())], scrollArea);
}


void MainWindow::on_actionZoomIn_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QScrollArea* scrollArea = getFocusedArea();
    if (scrollArea == NULL)
        return;
    scaleImage(1.25, scrollArea);
}

void MainWindow::on_actionZoomOut_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QScrollArea* scrollArea = getFocusedArea();
    if (scrollArea == NULL)
        return;
    scaleImage(0.80, scrollArea);
}

//menu outils
void MainWindow::on_actionAffichage_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherHistogramme (label);
}

void MainWindow::on_actionNegatif_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherHistogrammeNegatif (label);
}

void MainWindow::on_actionAddition_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
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

//menu filtrage
void MainWindow::on_actionLaplacien_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherLaplacien (label);
}

//menu segmentation
void MainWindow::on_actionManuelSimple_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherSeuillageManuelSimple (label);
}

void MainWindow::on_actionManuelDouble_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherSeuillageManuelDouble (label);
}

void MainWindow::on_actionSeuillageParHysteresis_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherSeuillageParHysteresis (label);
}

void MainWindow::on_actionGradientXSobel_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherGradientSobel (label, SOBEL_X);
}

void MainWindow::on_actionGradientYSobel_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QLabel* label = getFocusedLabel();
    if (label == NULL)
        return;
    afficherGradientSobel (label, SOBEL_Y);
}

