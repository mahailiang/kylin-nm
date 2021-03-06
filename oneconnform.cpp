/*
 * Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
 *
 */

#include "oneconnform.h"
#include "ui_oneconnform.h"
#include "mainwindow.h"
#include "wireless-security/dlgconnhidwifi.h"

extern int currentActWifiSignalLv;

OneConnForm::OneConnForm(QWidget *parent, MainWindow *mainWindow, ConfForm *confForm, KSimpleNM *ksnm) :
    QWidget(parent),
    ui(new Ui::OneConnForm)
{
    ui->setupUi(this);

    ui->btnConnSub->setText(tr("Connect"));//"设置"
    ui->btnConn->setText(tr("Connect"));//"连接"
    ui->btnConnPWD->setText(tr("Connect"));//"连接"
    ui->btnDisConn->setText(tr("Disconnect"));//"断开连接"
    ui->btnHideConn->setText(tr("Connect"));//"连接"
    ui->lePassword->setText(tr(""));//"连接"

    ui->lbConned->setAlignment(Qt::AlignLeft);
    ui->lbLoadUp->setAlignment(Qt::AlignLeft);
    ui->lbLoadDown->setAlignment(Qt::AlignLeft);
    ui->lePassword->setEchoMode(QLineEdit::Password);
    ui->btnConnPWD->setEnabled(false);

    ui->lbInfo->setStyleSheet("QLabel{font-size:14px;color:rgba(255,255,255,0.57);}");
    ui->wbg->setStyleSheet("#wbg{border-radius:4px;background-color:rgba(255,255,255,0);}");
                             // "#wbg:Hover{border-radius:4px;background-color:rgba(255,255,255,0.1);}");
    ui->wbg_2->setStyleSheet("#wbg_2{border-radius:4px;background-color:rgba(255,255,255,0.1);}");
    ui->wbg_3->setStyleSheet("#wbg_3{border-radius:4px;background-color:rgba(255,255,255,0.1);}");
    ui->lbName->setStyleSheet("QLabel{font-size:14px;color:rgba(255,255,255,0.91);}");
    ui->lbConned->setStyleSheet("QLabel{font-size:14px;color:rgba(255,255,255,0.57);}");
    ui->lbLoadUp->setStyleSheet("QLabel{font-size:14px;color:rgba(255,255,255,0.57);}");
    ui->lbLoadDown->setStyleSheet("QLabel{font-size:14px;color:rgba(255,255,255,0.57);}");
    ui->lePassword->setStyleSheet("QLineEdit{border:1px solid rgba(61,107,229,1);border-radius:4px;"
                                  "background:rgba(0,0,0,0.2);color:rgba(255,255,255,0.35);font-size:14px;}");
    ui->checkBoxPwd->setStyleSheet("QCheckBox::indicator {width: 18px; height: 9px;}"
                                   "QCheckBox::indicator:checked {image: url(:/res/h/show-pwd.png);}"
                                   "QCheckBox::indicator:unchecked {image: url(:/res/h/hide-pwd.png);}");
    ui->btnConnSub->setStyleSheet("QPushButton{border:0px;border-radius:4px;background-color:rgba(61,107,229,1);color:white;font-size:14px;}"
                               "QPushButton:Hover{border:0px solid rgba(255,255,255,0.2);border-radius:4px;background-color:rgba(107,142,235,1);}"
                               "QPushButton:Pressed{border-radius:4px;background-color:rgba(50,87,202,1);}");
    ui->btnConn->setStyleSheet("QPushButton{border:0px;border-radius:4px;background-color:rgba(61,107,229,1);color:white;font-size:14px;}"
                               "QPushButton:Hover{border:0px solid rgba(255,255,255,0.2);border-radius:4px;background-color:rgba(107,142,235,1);}"
                               "QPushButton:Pressed{border-radius:4px;background-color:rgba(50,87,202,1);}");
    ui->btnConnPWD->setStyleSheet("QPushButton{border:0px;border-radius:4px;background-color:rgba(255,255,255,0.12);color:white;font-size:14px;}"
                               "QPushButton:Hover{border:0px solid rgba(255,255,255,0.2);border-radius:4px;background-color:rgba(255,255,255,0.2);}"
                               "QPushButton:Pressed{border-radius:4px;background-color:rgba(255,255,255,0.08);}");
    ui->btnDisConn->setStyleSheet("QPushButton{border:0px;border-radius:4px;background-color:rgba(255,255,255,0.12);color:white;font-size:14px;}"
                               "QPushButton:Hover{border:0px solid rgba(255,255,255,0.2);border-radius:4px;background-color:rgba(255,255,255,0.2);}"
                               "QPushButton:Pressed{border-radius:4px;background-color:rgba(255,255,255,0.08);}");
    ui->btnHideConn->setStyleSheet("QPushButton{border:0px;border-radius:4px;background-color:rgba(61,107,229,1);color:white;font-size:14px;}"
                               "QPushButton:Hover{border:0px solid rgba(255,255,255,0.2);border-radius:4px;background-color:rgba(107,142,235,1);}"
                               "QPushButton:Pressed{border-radius:4px;background-color:rgba(50,87,202,1);}");
    ui->lbLoadDownImg->setStyleSheet("QLabel{background-image:url(:/res/x/load-down.png);}");
    ui->lbLoadUpImg->setStyleSheet("QLabel{background-image:url(:/res/x/load-up.png);}");
    ui->lbWaiting->setStyleSheet("QLabel{border:0px;border-radius:4px;background-color:rgba(61,107,229,1);}");
    ui->lbWaitingIcon->setStyleSheet("QLabel{border:0px;background-color:transparent;}");

    ui->checkBoxPwd->setFocusPolicy(Qt::NoFocus);
    ui->btnConnSub->setFocusPolicy(Qt::NoFocus);
    ui->btnConn->setFocusPolicy(Qt::NoFocus);
    ui->btnConnPWD->setFocusPolicy(Qt::NoFocus);
    ui->btnDisConn->setFocusPolicy(Qt::NoFocus);
    ui->btnHideConn->setFocusPolicy(Qt::NoFocus);

    ui->wbg->show();
    ui->wbg_2->hide();
    ui->wbg_3->hide();
    ui->lbName->show();
    ui->lbInfo->hide();
    ui->lePassword->hide();
    ui->checkBoxPwd->hide();
    ui->btnConnSub->hide();
    ui->btnConn->hide();
    ui->btnDisConn->hide();
    ui->btnConnPWD->hide();
    ui->btnHideConn->hide();
    ui->line->show();
    ui->lbLoadDownImg->hide();
    ui->lbLoadUpImg->hide();
    ui->lbWaiting->hide();
    ui->lbWaitingIcon->hide();

    this->mw = mainWindow;
    this->cf = confForm;
    this->ks = ksnm;

    this->isSelected = false;
    this->isActive = false;

    ui->wbg->setAttribute(Qt::WA_Hover,true);//开启悬停事件
    ui->wbg->installEventFilter(this);       //安装事件过滤器
    ui->btnConn->setAttribute(Qt::WA_Hover,true);//开启悬停事件
    ui->btnConn->installEventFilter(this);       //安装事件过滤器

    connect(ui->lePassword, SIGNAL(returnPressed()), this, SLOT(on_btnConnPWD_clicked()));
    ui->btnConn->setShortcut(Qt::Key_Return);//将字母区回车键与登录按钮绑定在一起

    this->waitTimer = new QTimer(this);
    connect(waitTimer, SIGNAL(timeout()), this, SLOT(waitAnimStep()));

    connect(mw, SIGNAL(waitWifiStop()), this, SLOT(stopWaiting()));
}

OneConnForm::~OneConnForm()
{
    delete ui;
}

void OneConnForm::mousePressEvent(QMouseEvent *){
    emit selectedOneWifiForm(wifiName);
}

//事件过滤器
bool OneConnForm::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->wbg) {
        if(event->type() == QEvent::HoverEnter) {
            ui->btnConn->show();
            ui->wbg->setStyleSheet("#wbg{border-radius:4px;background-color:rgba(255,255,255,0.1);}");
            return true;
        } else if(event->type() == QEvent::HoverLeave){
            ui->btnConn->hide();
            ui->wbg->setStyleSheet("#wbg{border-radius:4px;background-color:rgba(255,255,255,0);}");
            return true;
        }
    }

    if(obj == ui->btnConn) {
        if(event->type() == QEvent::HoverEnter) {
            ui->wbg->hide();
            ui->btnConn->show();
            return true;
        } else if(event->type() == QEvent::HoverLeave){
            ui->wbg->show();
            return true;
        }
    }

    return QWidget::eventFilter(obj,event);
}

// 是否当前连接的网络，字体设置不同
void OneConnForm::setAct(bool isAct){
    if(isAct){
        ui->lbName->setStyleSheet("QLabel{font-size:14px;color:#ffffff;}");
        ui->lbConned->show();
    }else{
        ui->lbName->setStyleSheet("QLabel{font-size:14px;color:#ffffff;}");
        ui->lbConned->hide();
    }
    isActive = isAct;
}

//点击窗口最上面的item时
void OneConnForm::setTopItem(bool isSelected){
    if(isSelected){
        resize(422, 148);
        ui->wbg_3->show();
        ui->lbInfo->show();

        this->isSelected = true;
    }else{
        resize(422, 60);
        ui->lePassword->setText("");
        ui->wbg_3->hide();
        ui->lbInfo->hide();

        this->isSelected = false;
    }

    ui->wbg->hide();
    ui->wbg_2->hide();
    ui->lbSignal->show();
    ui->lePassword->hide();
    ui->checkBoxPwd->hide();
    ui->line->hide();
    ui->btnConn->hide();
    ui->btnConnPWD->hide();
    ui->btnHideConn->hide();
    ui->lbLoadUpImg->show();
    ui->lbLoadDownImg->show();
    if (isConnected){
        // ui->lbLoadUp->setText("0Kb/s");
        // ui->lbLoadDown->setText("0Kb/s");
        ui->lbLoadUp->hide();
        ui->lbLoadDown->hide();
        if (this->isWaiting){
            ui->btnDisConn->hide();
        }else{
            ui->btnDisConn->show();
        }
    }else{
        // ui->lbLoadUp->setText("0Kb/s");
        // ui->lbLoadDown->setText("0Kb/s");
        ui->lbLoadUp->hide();
        ui->lbLoadDown->hide();
        ui->btnDisConn->hide();
    }
}
// 点击窗口下面的item时
void OneConnForm::setSelected(bool isSelected, bool isCurrName){
    if(isSelected){
        resize(422, 148);
        ui->line->hide();
        ui->wbg->hide();
        ui->wbg_2->hide();
        ui->wbg_3->show();
        ui->lbInfo->show();
        ui->btnConn->hide();
        ui->btnConnSub->show();

        this->isSelected = true;
    }else{
        resize(422, 60);
        ui->lePassword->setText(tr(""));
        ui->lePassword->setStyleSheet("QLineEdit{border:1px solid rgba(61,107,229,1);border-radius:4px;"
                                      "background:rgba(0,0,0,0.2);color:rgba(255,255,255,0.35);font-size:14px;}");
        ui->lePassword->setEchoMode(QLineEdit::Password);
        ui->checkBoxPwd->setChecked(false);

        ui->line->show();
        ui->wbg->show();
        ui->wbg_2->hide();
        ui->wbg_3->hide();
        ui->lbInfo->hide();
        if (isCurrName){
            ui->btnConn->show();
        }else{
            ui->btnConn->hide();
        }
        ui->btnConnSub->hide();

        this->isSelected = false;
    }

    ui->lePassword->hide();
    ui->checkBoxPwd->hide();
    ui->btnConnPWD->hide();

    ui->lbSignal->show();
    ui->btnDisConn->hide();
    ui->btnHideConn->hide();
}
// 点击连接隐藏wifi的item时
void OneConnForm::setHideItem(bool isHideItem, bool isShowHideBtn){
    if (isHideItem){
        ui->lbName->move(14, 20);
        ui->wbg->hide();
        ui->btnConn->hide();
    } else {
        ui->lbName->move(62, 8);
        ui->wbg->show();
        ui->btnConn->show();
    }

    if (isShowHideBtn){
        ui->btnHideConn->show();
    } else{
        ui->btnHideConn->hide();
    }
}

void OneConnForm::setConnedString(bool showLable, QString str, QString str1){
    if (!showLable){
        ui->lbConned->setText(str1);
        ui->lbConned->hide();
        ui->lbName->move(63, 18);
    }else{
        ui->lbConned->setText(str);
    }
}

void OneConnForm::setName(QString name){
    ui->lbName->setText(name);
    wifiName = name;
}
void OneConnForm::setSpecialName(QString name)
{
    ui->lbName->setText(tr("Connect to Hidden Wi-Fi Network")); //连接到隐藏的 Wi-Fi 网络
    wifiName = name;
}

QString OneConnForm::getName()
{
    return ui->lbName->text();
}

void OneConnForm::setRate(QString rate){
    QString txt(tr("Rate"));//"速率"
    this->setToolTip("<span style=\"font-size:13px;border:0px;background-color:#3593b5;color:white;\">&nbsp; " + txt + ": " + rate + " &nbsp;</span>");
    QString rateStr = rate.split(" ").at(0);
    int rateNum = rateStr.toInt();
}

void OneConnForm::setLine(bool isShow)
{
    if(isShow){
        ui->line->show();
    }else{
        ui->line->hide();
    }
}

void OneConnForm::setSignal(QString lv, QString secu){
    int signal = lv.toInt();
    if (secu == "--" || secu == ""){
        hasPwd = false;
    }else{
        hasPwd = true;
    }

    if(signal > 75){
        if(hasPwd){
            ui->lbSignal->setStyleSheet("QLabel{background:url(:/res/w/wifi-full-pwd.png);}");
        }else{
            ui->lbSignal->setStyleSheet("QLabel{background:url(:/res/w/wifi-full.png);}");
        }
        signalLv = 1;
    }
    if(signal > 55 && signal <= 75){
        if(hasPwd){
            ui->lbSignal->setStyleSheet("QLabel{background:url(:/res/w/wifi-high-pwd.png);}");
        }else{
            ui->lbSignal->setStyleSheet("QLabel{background:url(:/res/w/wifi-high.png);}");
        }
        signalLv = 2;
    }
    if(signal > 35 && signal <= 55){
        if(hasPwd){
            ui->lbSignal->setStyleSheet("QLabel{background:url(:/res/w/wifi-medium-pwd.png);}");
        }else{
            ui->lbSignal->setStyleSheet("QLabel{background:url(:/res/w/wifi-medium.png);}");
        }
        signalLv = 3;
    }
    if(signal > 15 && signal <= 35){
        if(hasPwd){
            ui->lbSignal->setStyleSheet("QLabel{background:url(:/res/w/wifi-low-pwd.png);}");
        }else{
            ui->lbSignal->setStyleSheet("QLabel{background:url(:/res/w/wifi-low.png);}");
        }
        signalLv = 4;
    }
    if(signal <= 15){
        if(hasPwd){
            ui->lbSignal->setStyleSheet("QLabel{background:url(:/res/w/wifi-none-pwd.png);}");
        }else{
            ui->lbSignal->setStyleSheet("QLabel{background:url(:/res/w/wifi-none.png);}");
        }
        signalLv = 4;
    }
}

void OneConnForm::setWifiInfo(QString str1, QString str2, QString str3)
{
    QString str = "Wi-Fi安全性：" + str1 + "\n信号强度：" + str2 + "%\n物理地址(MAC)：" + str3;
    ui->lbInfo->setText(str);
}

void OneConnForm::slotConnWifi()
{
//    mw->startLoading();
    this->startWaiting(true);
    emit sigConnWifi(ui->lbName->text());
}
void OneConnForm::slotConnWifiPWD(){
//    mw->startLoading();
    this->startWaiting(true);
    emit sigConnWifiPWD(ui->lbName->text(), ui->lePassword->text());
}

//点击后断开wifi网络
void OneConnForm::on_btnDisConn_clicked()
{
    this->startWaiting(false);

    mw->is_stop_check_net_state = 1;
    mw->on_btnHotspotState();
    kylin_network_set_con_down(ui->lbName->text().toUtf8().data());
    disconnect(this, SIGNAL(selectedOneWifiForm(QString)), mw, SLOT(oneWifiFormSelected(QString)));
    emit disconnActiveWifi();
}

//点击列表item扩展时会出现该按钮 用于连接网络
void OneConnForm::on_btnConnSub_clicked()
{
    if (ui->lbConned->text() == "--" || ui->lbConned->text() == " "){
        on_btnConnPWD_clicked();
        return;
    }

    mw->is_stop_check_net_state = 1;
    QThread *t = new QThread();
    BackThread *bt = new BackThread();
    bt->moveToThread(t);
    connect(t, SIGNAL(finished()), t, SLOT(deleteLater()));
    connect(t, SIGNAL(started()), this, SLOT(slotConnWifi()));
    connect(this, SIGNAL(sigConnWifi(QString)), bt, SLOT(execConnWifi(QString)));
    connect(bt, SIGNAL(connDone(int)), mw, SLOT(connWifiDone(int)));
    connect(bt, SIGNAL(connDone(int)), this, SLOT(slotConnWifiResult(int)));
    connect(bt, SIGNAL(btFinish()), t, SLOT(quit()));
    t->start();
}

//无需密码的wifi连接
void OneConnForm::on_btnConn_clicked()
{
    if (ui->lbConned->text() == "--" || ui->lbConned->text() == " "){
        on_btnConnPWD_clicked();
        return;
    }

    mw->is_stop_check_net_state = 1;
    QThread *t = new QThread();
    BackThread *bt = new BackThread();
    bt->moveToThread(t);
    connect(t, SIGNAL(finished()), t, SLOT(deleteLater()));
    connect(t, SIGNAL(started()), this, SLOT(slotConnWifi()));
    connect(this, SIGNAL(sigConnWifi(QString)), bt, SLOT(execConnWifi(QString)));
    connect(bt, SIGNAL(connDone(int)), mw, SLOT(connWifiDone(int)));
    connect(bt, SIGNAL(connDone(int)), this, SLOT(slotConnWifiResult(int)));
    connect(bt, SIGNAL(btFinish()), t, SLOT(quit()));
    t->start();
}

//需要密码的wifi连接
void OneConnForm::on_btnConnPWD_clicked()
{
    mw->is_stop_check_net_state = 1;
    QThread *t = new QThread();
    BackThread *bt = new BackThread();
    bt->moveToThread(t);
    connect(t, SIGNAL(finished()), t, SLOT(deleteLater()));
    connect(t, SIGNAL(started()), this, SLOT(slotConnWifiPWD()));
    connect(this, SIGNAL(sigConnWifiPWD(QString, QString)), bt, SLOT(execConnWifiPWD(QString, QString)));
    connect(bt, SIGNAL(connDone(int)), mw, SLOT(connWifiDone(int)));
    connect(bt, SIGNAL(connDone(int)), this, SLOT(slotConnWifiResult(int)));
    connect(bt, SIGNAL(btFinish()), t, SLOT(quit()));
    t->start();
}

//点击后弹出连接隐藏wifi网络窗口
void OneConnForm::on_btnHideConn_clicked()
{
    QApplication::setQuitOnLastWindowClosed(false);
    DlgConnHidWifi *connHidWifi = new DlgConnHidWifi(0, mw);
    connect(connHidWifi, SIGNAL(reSetWifiList() ), mw, SLOT(on_btnWifiList_clicked()) );
    connHidWifi->show();
}

//设置密码隐藏或可见
void OneConnForm::on_checkBoxPwd_stateChanged(int arg1)
{
    if (arg1 == 0) {
        ui->lePassword ->setEchoMode(QLineEdit::Password);
    } else {
        ui->lePassword->setEchoMode(QLineEdit::Normal);
    }
}

void OneConnForm::on_lePassword_textEdited(const QString &arg1)
{
    ui->lePassword->setStyleSheet("QLineEdit{border:2px solid rgba(28, 47, 146, 1);border-radius:4px;"
                                  "background:rgba(0,0,0,0.2);color:rgba(255,255,255,0.91);font-size:14px;}");

    if (ui->lePassword->text().size() < 5){
        ui->btnConnPWD->setStyleSheet("QPushButton{border:0px;border-radius:4px;background-color:rgba(255,255,255,0.12);color:white;font-size:14px;}"
                                   "QPushButton:Hover{border:0px solid rgba(255,255,255,0.2);border-radius:4px;background-color:rgba(255,255,255,0.2);}"
                                   "QPushButton:Pressed{border-radius:4px;background-color:rgba(255,255,255,0.08);}");
        ui->btnConnPWD->setEnabled(false);
    } else {
        ui->btnConnPWD->setStyleSheet("QPushButton{border:0px;border-radius:4px;background-color:rgba(61,107,229,1);color:white;font-size:14px;}"
                                      "QPushButton:Hover{border:0px solid rgba(255,255,255,0.2);border-radius:4px;background-color:rgba(107,142,235,1);}"
                                      "QPushButton:Pressed{border-radius:4px;background-color:rgba(50,87,202,1);}");
        ui->btnConnPWD->setEnabled(true);
    }
}

// Wifi连接结果，0成功 1失败 2没有配置文件
void OneConnForm::slotConnWifiResult(int connFlag){
    qDebug()<<"Function slotConnWifiResult receives a number: "<<connFlag;

    if(connFlag == 2){
        mw->currSelNetName = "";
        emit selectedOneWifiForm(ui->lbName->text());

        resize(422, 118);
        ui->wbg->hide();
        ui->wbg_2->show();
        ui->wbg_3->hide();
        ui->lbInfo->hide();
        ui->btnHideConn->hide();
        ui->btnDisConn->hide();
        ui->btnConn->hide();
        ui->btnConnSub->hide();
        ui->lbInfo->hide();

        ui->lePassword->show();
        ui->checkBoxPwd->show();
        ui->btnConnPWD->show();

        this->isSelected = true;
    }

    if(connFlag == 1){
        // 使用配置文件连接失败，需要删除该配置文件
        QString txt(tr("Conn Wifi Failed"));//"连接 Wifi 失败"
        syslog(LOG_DEBUG, "Try to connect wifi named %s, but failed, will delete it's configuration file", ui->lbName->text().toUtf8().data());
        QString cmd = "export LANG='en_US.UTF-8';export LANGUAGE='en_US';nmcli connection delete '" + ui->lbName->text() + "';notify-send '" + txt + "...' -t 3800";
        system(cmd.toUtf8().data());
    }

    // 设置全局变量，当前连接Wifi的信号强度
    currentActWifiSignalLv = signalLv;

    this->stopWaiting();
//    if (connFlag != 0){
//        mw->stopLoading();
//    }
}

void OneConnForm::waitAnimStep(){
    QString qpmQss = "QLabel{background-image:url(':/res/s/conning-a/";
    qpmQss.append(QString::number(this->waitPage));
    qpmQss.append(".png');}");
    ui->lbWaitingIcon->setStyleSheet(qpmQss);

    this->waitPage --;

    if(this->waitPage < 1){
        this->waitPage = 8;
    }
}

void OneConnForm::startWaiting(bool isConn){
    this->isWaiting = true;
    if (isConn){
        ui->lbWaiting->setStyleSheet("QLabel{border:0px;border-radius:4px;background-color:rgba(61,107,229,1);}");
    }else{
        ui->btnDisConn->hide();
        ui->lbWaiting->setStyleSheet("QLabel{border:0px;border-radius:4px;background-color:rgba(255,255,255,0.12);}");
    }
    this->waitPage = 8;
    this->waitTimer->start(150);
    ui->lbWaiting->show();
    ui->lbWaitingIcon->show();

    mw->setTrayLoading(true);
}

void OneConnForm::stopWaiting(){
    this->isWaiting = false;
    this->waitTimer->stop();
    ui->lbWaiting->hide();
    ui->lbWaitingIcon->hide();

    mw->setTrayLoading(false);
}
