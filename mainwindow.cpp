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
    //ouvrirImage("../TCIMAG_ressources/lena.jpg");
    //ouvrirImage("../TCIMAG_ressources/lena.jpeg");
    //ouvrirImage("../TCIMAG_ressources/lena.png");
    //ouvrirImage("../TCIMAG_ressources/lena.pgm");
    //ouvrirImage("../TCIMAG_ressources/lena.ppm");
    //ouvrirImage("../TCIMAG_ressources/lena.tiff");

    ui->actionAffichage->setEnabled(true);
    //ui->actionEgalisation
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
        updateZoomActions((QLabel*) watched->children().first()->children().first());
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

void QImageTocvMat(QImage& in, cv::Mat& out) {
    in = in.convertToFormat(QImage::Format_RGB888, Qt::ColorOnly);
    ////cv::Mat (int _rows, int _cols, int _type, void* _data, size_t _step=AUTO_STEP);
    cv::Mat matRGB(in.width(), in.height(), CV_8UC3, in.bits(), in.bytesPerLine());
    cv::cvtColor(matRGB, out, CV_RGB2BGR);
}

void cvMatToQImage(cv::Mat& in, QImage& out) {
    cv::cvtColor(in, in, CV_BGR2RGB);
    ////QImage::QImage ( const uchar * data, int width, int height, int bytesPerLine, Format format )
    out = QImage((uchar*)in.data, in.cols, in.rows, in.step, QImage::Format_RGB888);
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
    creerFenetre (imageToQPixmap (nomFichier), QDir (tr (nomFichier)).absolutePath());

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
    QLabel* image = (QLabel*) paneau->children().first()->children().first();
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

void MainWindow::afficherHistogramme (QLabel* label) {
    QImage image = label->pixmap()->toImage();
    QString titre = QString("Histogramme pour : ") + windowTitle[qHash(label)];
    calculerHistogramme(image, titre);
}

void MainWindow::calculerHistogramme(QImage argbImage, QString titre) {
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
    scaleImage(1/scaleFactor[qHash((QLabel*) scrollArea->children().first()->children().first())], scrollArea);
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

void MainWindow::on_actionAffichage_triggered () {
    ////
    ////MainWindow -> centralWidget:QMdiArea -> QWidget -> QMdiSubWindow[] -> QScrollArea <hasFocus> -> QWidget <hasFocus> -> QLabel
    ////
    ////
    QScrollArea* scrollArea = getFocusedArea();
    if (scrollArea == NULL)
        return;
    afficherHistogramme ((QLabel*) scrollArea->children().first()->children().first());
}

