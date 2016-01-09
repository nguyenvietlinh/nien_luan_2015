#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "QLabel"
#include "qpixmap.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_browse_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Select File To Open","C:/CVIPtools/images","*.bmp,*.jpg,*.tif");
    if(filename.isEmpty())
           return;
    ui->ln_FileName->setText(filename);
}


void MainWindow::on_bt_apply_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);
    int c = ui->ln_c->text().toInt();
    for(int x=0; x<image_in.width();x++)
        for(int y=0; y<image_in.height();y++){
            QRgb color = image_in.pixel(x,y);
            int Gray = qGray(color);
            int Gray_out = Gray + c;
            if(Gray_out>255)
                Gray_out=255;
            else if (Gray_out<0)
                Gray_out=0;
            QRgb color_out = qRgb(Gray_out,Gray_out,Gray_out);
            image_out.setPixel(x,y,color_out);
        }
    QLabel *label_in=new QLabel();
    label_in ->setPixmap(QPixmap::fromImage(image_in));
    label_in ->show();
    QLabel *label_out =new QLabel();
    label_out ->setPixmap(QPixmap::fromImage(image_out));
    label_out ->show();
}

void MainWindow::on_bt_Apply1_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);
    int c = ui->ln_c->text().toInt();
    for(int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height(); y++){
            QRgb rgb = image_in.pixel(x,y);
            QColor color(rgb);
            int h,s,v;
            color.getHsv(&h,&s,&v);
            int out=v+c;
            if(out>255) out=255;
            else if (out<0) out=0;
            QColor color_out = QColor::fromHsv(h,s,out);
            image_out.setPixel(x,y,color_out.rgb());
        }
    QLabel *label_in1=new QLabel();
    label_in1 ->setPixmap(QPixmap::fromImage(image_in));
    label_in1 ->show();
    QLabel *label_out1 =new QLabel();
    label_out1 ->setPixmap(QPixmap::fromImage(image_out));
    label_out1 ->show();
}

void MainWindow::on_bt_apply_tp_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);
    float c1=ui->ln_c1->text().toFloat();
    for(int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height();y++){
            QRgb color = image_in.pixel(x,y);
            int Gray=qGray(color);
            float Gray_out = Gray*c1;
            if(Gray_out>255) Gray_out=255;
            QRgb color_out= qRgb(Gray_out,Gray_out,Gray_out);
            image_out.setPixel(x,y,color_out);
        }
    QLabel *label_in2=new QLabel();
    label_in2->setPixmap(QPixmap::fromImage(image_in));
    label_in2->show();
    QLabel *label_out2=new QLabel();
    label_out2->setPixmap(QPixmap::fromImage(image_out));
    label_out2->show();
}


void MainWindow::on_bt_apply_tp1_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);
    float c1 = ui->ln_c1->text().toFloat();
    for(int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height(); y++){
            QRgb rgb = image_in.pixel(x,y);
            QColor color(rgb);
            int h,s,v;
            color.getHsv(&h,&s,&v);
            float out=v*c1;
            if(out>255) out=255;
            QColor color_out = QColor::fromHsv(h,s,out);
            image_out.setPixel(x,y,color_out.rgb());
        }
    QLabel *label_in3=new QLabel();
    label_in3 ->setPixmap(QPixmap::fromImage(image_in));
    label_in3 ->show();
    QLabel *label_out3 =new QLabel();
    label_out3 ->setPixmap(QPixmap::fromImage(image_out));
    label_out3 ->show();
}

void MainWindow::on_bt_xuly_pn_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);
    int n=ui->ln_n->text().toInt();
    for(int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height(); y++){
            QRgb color = image_in.pixel(x,y);
            int out= qGray(color);
            if(out<n) out=0;
            else out=255;
            QRgb color_out= qRgb(out,out,out);
            image_out.setPixel(x,y,color_out);
        }
    QLabel *label_in4=new QLabel();
    label_in4 ->setPixmap(QPixmap::fromImage(image_in));
    label_in4 ->show();
    QLabel *label_out4 =new QLabel();
    label_out4 ->setPixmap(QPixmap::fromImage(image_out));
    label_out4 ->show();
}

void MainWindow::on_bt_browse1_clicked()
{
    QString filename1=QFileDialog::getOpenFileName(this,"Select To Open","C:/CVIPtools/images","*.bmp,*.jpg,*.tif");
    if(filename1.isEmpty())
        return;
    ui->ln_Filename1->setText(filename1);
}

void MainWindow::on_bt_Add_clicked()
{
    QImage image_in1(ui->ln_FileName->text());
    QImage image_in2(ui->ln_Filename1->text());
    int max_width,min_width, max_height, min_height;
    if(image_in1.width()>image_in2.width()){
        max_width=image_in1.width();
        min_width=image_in2.width();
    }
    else{
        max_width=image_in2.width();
        min_width=image_in1.width();
    }
    if(image_in1.height()>image_in2.height()){
        max_height=image_in1.height();
        min_height=image_in2.height();
    }
    else{
        max_height=image_in2.height();
        min_height=image_in1.height();
    }
    QImage image_kq(max_width,max_height,QImage::Format_ARGB32);
    float ratio=ui->ln_ratio->text().toFloat();
    for(int x=0; x<min_width; x++)
            for(int y=0 ;y<min_height; y++){
                QColor color1=image_in1.pixel(x,y);
                QColor color2=image_in2.pixel(x,y);

                int imgred= color1.red()*ratio+color2.red()*(1-ratio);
                int imggreen= color1.green()*ratio+color2.green()*(1-ratio);
                int imgblue= color1.blue()*ratio+color2.blue()*(1-ratio);

                image_kq.setPixel(x,y,qRgb(imgred,imggreen,imgblue));
            }
     QLabel *label_in1_4= new QLabel();
     label_in1_4->setPixmap(QPixmap::fromImage(image_in1));
     label_in1_4->show();

     QLabel *label_in2_4=new QLabel();
     label_in2_4->setPixmap(QPixmap::fromImage(image_in2));
     label_in2_4->show();

     QLabel *label_kq_4= new QLabel();
     label_kq_4->setPixmap(QPixmap::fromImage(image_kq));
     label_kq_4->show();
}

void MainWindow::on_bt_Sub_clicked()
{
    QImage image_in1(ui->ln_FileName->text());
    QImage image_in2(ui->ln_Filename1->text());
    int max_width,min_width, max_height, min_height;
    if(image_in1.width()>image_in2.width()){
        max_width=image_in1.width();
        min_width=image_in2.width();
    }
    else{
        max_width=image_in2.width();
        min_width=image_in1.width();
    }
    if(image_in1.height()>image_in2.height()){
        max_height=image_in1.height();
        min_height=image_in2.height();
    }
    else{
        max_height=image_in2.height();
        min_height=image_in1.height();
    }
    QImage image_kq(max_width,max_height,QImage::Format_ARGB32);
    float ratio=ui->ln_ratio->text().toFloat();
    for(int x=0; x<min_width; x++)
            for(int y=0 ;y<min_height; y++){
                QColor color1=image_in1.pixel(x,y);
                QColor color2=image_in2.pixel(x,y);

                int imgred= color1.red()*ratio-color2.red()*(1-ratio);
                int imggreen= color1.green()*ratio-color2.green()*(1-ratio);
                int imgblue= color1.blue()*ratio-color2.blue()*(1-ratio);

                image_kq.setPixel(x,y,qRgb(imgred,imggreen,imgblue));
            }
     QLabel *label_in1_5= new QLabel();
     label_in1_5->setPixmap(QPixmap::fromImage(image_in1));
     label_in1_5->show();

     QLabel *label_in2_5=new QLabel();
     label_in2_5->setPixmap(QPixmap::fromImage(image_in2));
     label_in2_5->show();

     QLabel *label_kq_5= new QLabel();
     label_kq_5->setPixmap(QPixmap::fromImage(image_kq));
     label_kq_5->show();
}

void MainWindow::Histogram(const QImage &img, const int &his_height){
    int h[256];
    for(int i=0; i<256; i++)
        h[i]=0;

    for(int x=0; x<img.width(); x++)
        for(int y=0; y<img.height(); y++){
            QRgb color= img.pixel(x,y);
            int Gray= qGray(color);
            h[Gray]++;
        }

    int max=0;
    for(int i=0; i<256; i++)
        if(h[i]>max) max=h[i];
    QImage img_his= QImage(256,his_height,QImage::Format_RGB888);
    img_his.fill(Qt::white);

    int lineHeight;
    for(int i=0; i<256; i++){
        lineHeight=his_height * h[i]/max;
        for(int j=his_height-1; j>= his_height-1-lineHeight; j--)
            img_his.setPixel(i,j,qRgb(0,0,255));
    }
    QImage image_out(img.width(),img.height(),QImage::Format_RGB888);
    QLabel *label_in=new QLabel();
    label_in->setPixmap(QPixmap::fromImage(img));
    label_in->show();

    QLabel *label_out=new QLabel();
    label_out->setPixmap(QPixmap::fromImage(img_his));
    label_out->show();
}

void MainWindow::draw_Histogram(const QImage &img, const int &height, const QString &str){
    int h[256];
    for(int i=0; i<256; i++)
        h[i]=0;

    for(int x=0; x<img.width(); x++)
        for(int y=0; y<img.height(); y++){
            QRgb color= img.pixel(x,y);
            int Gray= qGray(color);
            h[Gray]++;
        }

    int max=0;
    for(int i=0; i<256; i++)
        if(h[i]>max) max=h[i];
    QImage img_his= QImage(256,height,QImage::Format_RGB888);
    img_his.fill(Qt::white);

    int lineHeight;
    for(int i=0; i<256; i++){
        lineHeight=height * h[i]/max;
        for(int j=height-1; j>= height-1-lineHeight; j--)
            img_his.setPixel(i,j,qRgb(0,0,255));
    }
    QLabel *label_out=new QLabel();
    label_out->setPixmap(QPixmap::fromImage(img_his));
    label_out->setWindowTitle(str);
    label_out->show();
}

void MainWindow::on_bt_showH_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    Histogram(image_in,127);
}

void MainWindow::on_bt_showH1_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    int his_line=127;
    QImage his_img_r(256,his_line,QImage::Format_ARGB32);
    QImage his_img_g(256,his_line,QImage::Format_ARGB32);
    QImage his_img_b(256,his_line,QImage::Format_ARGB32);
    his_img_r.fill(Qt::white);
    his_img_g.fill(Qt::white);
    his_img_b.fill(Qt::white);
    int r[256], g[256], b[256];
    for(int i=0; i<256; i++){
        r[i]=0;
        g[i]=0;
        b[i]=0;
    }
    for(int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height(); y++){
            QColor color= image_in.pixel(x,y);
            int imgred= color.red();
            int imggreen= color.green();
            int imgblue= color.blue();
            r[imgred]++;
            g[imggreen]++;
            b[imgblue]++;
        }
    int max_r=0, max_g=0, max_b=0;
    for(int i=0; i<256; i++){
        if(r[i]>max_r) max_r=r[i];
        if(g[i]>max_g) max_g=g[i];
        if(b[i]>max_b) max_b=b[i];
    }
    int lineHeight_r, lineHeight_g, lineHeight_b;
    for(int i=0; i<256; i++){
        lineHeight_r=his_line * r[i]/max_r;
        lineHeight_g=his_line * g[i]/max_g;
        lineHeight_b=his_line * b[i]/max_b;
        for(int j=his_line; j>= his_line-1-lineHeight_r; j--)
            his_img_r.setPixel(i,j,qRgb(255,0,0));
        for(int j=his_line; j>= his_line-1-lineHeight_g; j--)
            his_img_g.setPixel(i,j,qRgb(0,255,0));
        for(int j=his_line; j>= his_line-1-lineHeight_b; j--)
            his_img_b.setPixel(i,j,qRgb(0,0,255));
    }
    QLabel *label_in=new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out1=new QLabel();
    label_out1->setPixmap(QPixmap::fromImage(his_img_r));
    label_out1->show();

    QLabel *label_out2=new QLabel();
    label_out2->setPixmap(QPixmap::fromImage(his_img_g));
    label_out2->show();

    QLabel *label_out3=new QLabel();
    label_out3->setPixmap(QPixmap::fromImage(his_img_b));
    label_out3->show();
}

void MainWindow::on_bt_showH3_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    int his_line= 127*3;
    QImage his_img(256,his_line,QImage::Format_ARGB32);
    his_img.fill(Qt::white);
    int r[256], g[256], b[256];
    for(int i=0; i<256; i++){
        r[i]=0;
        g[i]=0;
        b[i]=0;
    }
    for(int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height(); y++){
            QColor color= image_in.pixel(x,y);
            int imgred= color.red();
            int imggreen= color.green();
            int imgblue= color.blue();
            r[imgred]++;
            g[imggreen]++;
            b[imgblue]++;
        }
    int max_r=0, max_g=0, max_b=0;
    for(int i=0; i<256; i++){
        if(r[i]>max_r) max_r=r[i];
        if(g[i]>max_g) max_g=g[i];
        if(b[i]>max_b) max_b=b[i];
    }
    int lineHeight_r, lineHeight_g, lineHeight_b;
    for(int i=0; i<256; i++){
        lineHeight_r=(his_line/3) * r[i]/max_r;
        lineHeight_g=(his_line/3) * g[i]/max_g;
        lineHeight_b=(his_line/3) * b[i]/max_b;
        for(int j=his_line; j>= his_line-1-lineHeight_b; j--)
            his_img.setPixel(i,j,qRgb(0,0,255));
        for(int j=his_line-127; j>= his_line-127-lineHeight_g-1; j--)
            his_img.setPixel(i,j,qRgb(0,255,0));
        for(int j=his_line-(127*2); j>= his_line-127*2-lineHeight_r-1; j--)
            his_img.setPixel(i,j,qRgb(255,0,0));
    }
    QLabel *label_in=new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out=new QLabel();
    label_out->setPixmap(QPixmap::fromImage(his_img));
    label_out->show();
}

void MainWindow::on_bt_p2n_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);
    int n1=ui->ln_n1->text().toInt();
    int n2=ui->ln_n2->text().toInt();
    for(int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height(); y++){
            QRgb color = image_in.pixel(x,y);
            int out= qGray(color);
            if(out<n1) out=0;
            else if(out<n2) out=(n1+n2)/2;
            else out=255;
            QRgb color_out= qRgb(out,out,out);
            image_out.setPixel(x,y,color_out);
        }
    QLabel *label_in4=new QLabel();
    label_in4 ->setPixmap(QPixmap::fromImage(image_in));
    label_in4 ->show();
    QLabel *label_out4 =new QLabel();
    label_out4 ->setPixmap(QPixmap::fromImage(image_out));
    label_out4 ->show();
}



void MainWindow::on_bt_applyTCD_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);
    int max=0,min=255;
    for(int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height(); y++){
            QRgb color= image_in.pixel(x,y);
            int gray= qGray(color);
            if(gray>max) max=gray;
            if(gray<min) min=gray;
        }
    for(int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height(); y++){
            QRgb rgb= image_in.pixel(x,y);
            int gray= qGray(rgb);
            int gray_out=((gray-min)*255)/(max-min);
            image_in.setPixel(x,y,qRgb(gray,gray,gray));
            image_out.setPixel(x,y,qRgb(gray_out,gray_out,gray_out));
        }

    QLabel *label_in5=new QLabel();
    label_in5 ->setPixmap(QPixmap::fromImage(image_in));
    label_in5->setWindowTitle("Anh goc");
    label_in5 ->show();

    QLabel *label_out5 =new QLabel();
    label_out5 ->setPixmap(QPixmap::fromImage(image_out));
    label_out5->setWindowTitle("Anh ket qua");
    label_out5 ->show();

    draw_Histogram(image_in,127,"To chuc do anh goc");
    draw_Histogram(image_out,127,"To chuc do anh ket qua");
}

void MainWindow::on_bt_ApplyCBTCD_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);

    float h[256], hn[256], C[256];
    for(int i=0; i<256; i++){
        h[i]=0;
        hn[i]=0;
        C[i]=0;
    }

    for(int x=0; x<image_in.width(); x++)\
        for(int y=0; y<image_in.height(); y++){
            QRgb rgb= image_in.pixel(x,y);
            int gray= qGray(rgb);
            h[gray]++;
        }

    for(int i=0; i<256; i++){
        hn[i]= h[i]/(image_in.width()*image_in.height());
    }

    for(int i=0; i<256; i++)
        for(int j=0; j<=i; j++){
            C[i]=C[i]+hn[j];
        }

    for(int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height(); y++){
            QRgb rgb= image_in.pixel(x,y);
            int gray= qGray(rgb);
            int out= C[gray]*255;
            image_in.setPixel(x,y,qRgb(gray,gray,gray));
            image_out.setPixel(x,y,qRgb(out,out,out));
        }

    QLabel *label_in6= new QLabel();
    label_in6->setPixmap(QPixmap::fromImage(image_in));
    label_in6->setWindowTitle("Anh goc");
    label_in6->show();

    QLabel *label_out6= new QLabel();
    label_out6->setPixmap(QPixmap::fromImage(image_out));
    label_out6->setWindowTitle("Anh ket qua");
    label_out6->show();

    draw_Histogram(image_in,127,"To chuc do anh goc");
    draw_Histogram(image_out,127,"To chuc do anh ket qua");
}

void MainWindow::on_bt_LocAnhTB_Color_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);
    image_out.fill(Qt::white);

    int SumR, SumG, SumB;
    int cells=9;
    int margin=1;
    for(int x=margin; x<image_in.width()-margin; x++)
        for(int y=margin; y<image_in.height()-margin; y++){
            SumR=SumG=SumB=0;
            for(int i=-margin; i<=margin; i++)
                for(int j=-margin; j<=margin; j++){
                    QColor color= image_in.pixel(x+i,y+j);
                    SumR+= color.red();
                    SumG+= color.green();
                    SumB+= color.blue();
                }
            image_out.setPixel(x,y,qRgb(SumR/cells, SumG/cells, SumB/cells));
        }

    QLabel *label_in7= new QLabel();
    label_in7->setPixmap(QPixmap::fromImage(image_in));
    label_in7->setWindowTitle("Anh goc");
    label_in7->show();

    QLabel *label_out7=new QLabel();
    label_out7->setPixmap(QPixmap::fromImage(image_out));
    label_out7->setWindowTitle("Anh ket qua");
    label_out7->show();
}



void MainWindow::on_bt_LocAnhTB_Gray_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);
    image_out.fill(Qt::white);

    int Sum;
    int cells=9;
    int margin=1;
    for(int x=margin; x<image_in.width()-margin; x++)
        for(int y=margin; y<image_in.height()-margin; y++){
            Sum=0;
            for(int i=-margin; i<=margin; i++)
                for(int j=-margin; j<=margin; j++){
                    QRgb rgb=image_in.pixel(x+i,y+j);
                    int gray= qGray(rgb);
                    Sum+=gray;
                }
            image_out.setPixel(x,y,qRgb(Sum/cells,Sum/cells,Sum/cells));
        }

    QLabel *label_in8=new QLabel();
    label_in8->setPixmap(QPixmap::fromImage(image_in));
    label_in8->setWindowTitle("Anh goc");
    label_in8->show();

    QLabel *label_out8=new QLabel();
    label_out8->setPixmap(QPixmap::fromImage(image_out));
    label_out8->setWindowTitle("Anh ket qua");
    label_out8->show();
}



void MainWindow::on_bt_LocAnhMedian_Gray_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(), QImage::Format_ARGB32);
    image_out.fill(Qt::white);

    int h[9];
    int margin=1;
    for(int x=margin; x<image_in.width()-margin; x++)
        for(int y=margin; y<image_in.height()-margin; y++){
            int k=0;
            for(int i=-margin; i<=margin; i++)
                for(int j=-margin; j<=margin; j++){
                    QRgb rgb=image_in.pixel(x+i,y+j);
                    int gray= qGray(rgb);
                    h[k]=gray;
                    k++;
                }
            qSort(h,h+9);
            image_out.setPixel(x,y,qRgb(h[4],h[4],h[4]));
        }
    QLabel *label_in9=new QLabel();
    label_in9->setPixmap(QPixmap::fromImage(image_in));
    label_in9->setWindowTitle("Anh goc");
    label_in9->show();

    QLabel *label_out9=new QLabel();
    label_out9->setPixmap(QPixmap::fromImage(image_out));
    label_out9->setWindowTitle("Anh ket qua");
    label_out9->show();
}

void MainWindow::on_bt_LocAnhMedian_Color_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(),image_in.height(), QImage::Format_ARGB32);
    image_out.fill(Qt::white);

    int hr[9], hg[9], hb[9];
    int margin=1;
    for(int x=margin; x<image_in.width()-margin; x++)
        for(int y=margin; y<image_in.height()-margin; y++){
            int k=0;
            for(int i=-margin; i<=margin; i++)
                for(int j=-margin; j<=margin; j++)
            {
                    QColor color=image_in.pixel(x+i,y+j);
                    int red= color.red();
                    int green= color.green();
                    int blue= color.blue();
                    hr[k]=red;
                    hg[k]=green;
                    hb[k]=blue;
                    k++;
              }
            qSort(hr,hr+9);
            qSort(hg,hg+9);
            qSort(hb,hb+9);
            image_out.setPixel(x,y,qRgb(hr[4],hg[4],hb[4]));
        }
    QLabel *label_in10=new QLabel();
    label_in10->setPixmap(QPixmap::fromImage(image_in));
    label_in10->setWindowTitle("Anh goc");
    label_in10->show();

    QLabel *label_out10=new QLabel();
    label_out10->setPixmap(QPixmap::fromImage(image_out));
    label_out10->setWindowTitle("Anh ket qua");
    label_out10->show();
}

void MainWindow::on_btn_Gradient_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_ARGB32);
    image_out.fill(Qt::white);
    QRgb rgb1, rgb2;
    int gray1 = 0, gray2 = 0, gray_out = 0;
    for(int x = 0; x<image_in.width()-1; x++)
        for(int y = 0; y<image_in.height(); y++)
        {
            rgb1=image_in.pixel(x,y);
            gray1=qGray(rgb1);
            image_in.setPixel(x,y, qRgb(gray1, gray1, gray1));

            rgb2=image_in.pixel(x+1,y);
            gray2=qGray(rgb2);

            gray_out=abs(gray2-gray1);

            image_out.setPixel(x,y,qRgb(gray_out, gray_out, gray_out));
        }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->setWindowTitle("Image_in");
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->setWindowTitle("Image_out_Gx");
    label_out->show();
}

void MainWindow::on_btn_GradientY_clicked()
{

    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_ARGB32);
    image_out.fill(Qt::white);
    QRgb rgb1, rgb2;
    int gray1 = 0, gray2 = 0, gray_out = 0;
    for(int x = 0; x<image_in.width(); x++)
        for(int y = 0; y<image_in.height()-1; y++)
        {
            rgb1=image_in.pixel(x,y);
            gray1=qGray(rgb1);
            image_in.setPixel(x,y, qRgb(gray1, gray1, gray1));

            rgb2=image_in.pixel(x,y+1);
            gray2=qGray(rgb2);

            gray_out=abs(gray2-gray1);

            image_out.setPixel(x,y,qRgb(gray_out, gray_out, gray_out));
        }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->setWindowTitle("Image_in");
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->setWindowTitle("Image_out_Gy");
    label_out->show();
}

void MainWindow::on_btn_Roberts_X_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_ARGB32);
    image_out.fill(Qt::white);
    QRgb rgb1, rgb2;
    int gray1 = 0, gray2 = 0, gray_out = 0;
    for(int x = 0; x<image_in.width()-1; x++)
        for(int y = 0; y<image_in.height()-1; y++)
        {
            rgb1=image_in.pixel(x,y+1);
            gray1=qGray(rgb1);

            image_in.setPixel(x,y, qRgb(gray1, gray1, gray1));

            rgb2=image_in.pixel(x+1,y);
            gray2=qGray(rgb2);

            gray_out=abs(gray2-gray1);

            image_out.setPixel(x,y,qRgb(gray_out, gray_out, gray_out));
        }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->setWindowTitle("Image_in");
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->setWindowTitle("Image_out_Rx");
    label_out->show();
}

void MainWindow::on_btn_Roberts_Y_clicked()
{

    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_ARGB32);
    image_out.fill(Qt::white);
    QRgb rgb1, rgb2;
    int gray1 = 0, gray2 = 0, gray_out = 0;
    for(int x = 0; x<image_in.width()-1; x++)
        for(int y = 0; y<image_in.height()-1; y++)
        {
            rgb1=image_in.pixel(x,y);
            gray1=qGray(rgb1);

            image_in.setPixel(x,y, qRgb(gray1, gray1, gray1));

            rgb2=image_in.pixel(x+1,y+1);
            gray2=qGray(rgb2);

            gray_out=abs(gray2-gray1);

            image_out.setPixel(x,y,qRgb(gray_out, gray_out, gray_out));
        }
    QString selectedFilter;
    QString fileNam= QFileDialog::getSaveFileName(this, "Save image", "C:\CVIPtools\images",
                                                  "BMP (*.bmp);;PNG (*.png);;JPEG (*.jpeg);;All files (*.*)", &selectedFilter);
    if(selectedFilter == "BMP (*.bmp)")
        image_out.save(fileNam, "BMP");
    else if(selectedFilter == "PNG (*.png)")
        image_out.save(fileNam, "PNG");
    else if(selectedFilter == "JPEG (*.jpeg)")
        image_out.save(fileNam, "JPEG");
    else
        image_out.save(fileNam);


    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->setWindowTitle("Image_in");
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->setWindowTitle("Image_out_Ry");
    label_out->show();
}


void MainWindow::on_btn_Sobel_X_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_ARGB32);
    image_out.fill(Qt::white);

    int maskSize = 3;
    int margin =  maskSize/2;
    int mask_Sobel[maskSize][maskSize];
    int sum_mask;
    mask_Sobel[0][0] = -1; mask_Sobel[0][1]= -2; mask_Sobel[0][2]=-1;
    mask_Sobel[1][0] = 0; mask_Sobel[1][1]= 0; mask_Sobel[1][2]=0;
    mask_Sobel[2][0] = 1; mask_Sobel[2][1]= 2; mask_Sobel[2][2]=1;

    for(int x=margin; x<image_in.width()-margin; x++)
        for(int y=margin; y<image_in.height()-margin; y++)
        {
            sum_mask = 0;
            for(int i=-margin; i<=margin; i++)
                for(int j=-margin; j<=margin; j++)
                {
                    QRgb rgb = image_in.pixel(x+j, y+i);
                    int gray = qGray(rgb);
                    sum_mask+=(gray*mask_Sobel[i+margin][j+margin]);

                }
            image_out.setPixel(x,y, qRgb(abs(sum_mask),abs(sum_mask), abs(sum_mask)));
        }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->setWindowTitle("Image_in");
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->setWindowTitle("Image_out_Ry");
    label_out->show();

}

void MainWindow::on_btn_Sobel_Y_clicked()
{
    QImage image_in(ui->ln_FileName->text());
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_ARGB32);
    image_out.fill(Qt::white);

    int maskSize = 3;
    int margin =  maskSize/2;
    int mask_Sobel[maskSize][maskSize];
    int sum_mask;
    mask_Sobel[0][0] = -1; mask_Sobel[0][1]= 0; mask_Sobel[0][2]=1;
    mask_Sobel[1][0] = -2; mask_Sobel[1][1]= 0; mask_Sobel[1][2]=2;
    mask_Sobel[2][0] = -1; mask_Sobel[2][1]= 0; mask_Sobel[2][2]=1;

    for(int x=margin; x<image_in.width()-margin; x++)
        for(int y=margin; y<image_in.height()-margin; y++)
        {
            sum_mask = 0;
            for(int i=-margin; i<=margin; i++)
                for(int j=-margin; j<=margin; j++)
                {
                    QRgb rgb = image_in.pixel(x+j, y+i);
                    int gray = qGray(rgb);
                    sum_mask+=(gray*mask_Sobel[i+margin][j+margin]);

                }
            image_out.setPixel(x,y, qRgb(abs(sum_mask),abs(sum_mask), abs(sum_mask)));
        }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->setWindowTitle("Image_in");
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->setWindowTitle("Image_out_Ry");
    label_out->show();
}
