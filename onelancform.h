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

#ifndef ONELANCFORM_H
#define ONELANCFORM_H

#include <QWidget>
#include <QScreen>
#include <QThread>
#include <QEvent>

#include "confform.h"
#include "kylin-network-interface.h"
#include "backthread.h"
#include "ksimplenm.h"

class MainWindow;

namespace Ui {
class OneLancForm;
}

class OneLancForm : public QWidget
{
    Q_OBJECT

public:
    explicit OneLancForm(QWidget *parent = 0, MainWindow *mw = 0, ConfForm *confForm = 0, KSimpleNM *ksnm = 0);
    ~OneLancForm();

    void setName(QString name);
    void setIcon(bool isOn);
    void setLine(bool isShow);
    void setLanInfo(QString str1, QString str2, QString str3, QString str4);

    void setSelected(bool isSelected, bool isCurrName);
    void setTopItem(bool isSelected);
    void setAct(bool isAct);

    void setConnedString(bool showLable, QString str);

    bool isSelected;
    bool isActive;
    bool isConnected;
    QString lanName;

signals:
    void selectedOneLanForm(QString lanName);
    void connDone(int connFlag);
    void disconnActiveLan();

    void sigConnLan(QString);

protected:
    void mousePressEvent(QMouseEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_btnConn_clicked();
    void on_btnConnSub_clicked();
    void on_btnDisConn_clicked();

    void slotConnLan();

    void waitAnimStep();
    void startWaiting(bool isConn);
    void stopWaiting();

private:
    QTimer *waitTimer;
    int waitPage;

    Ui::OneLancForm *ui;
    MainWindow *mw;
    ConfForm *cf;
    KSimpleNM *ks;
};

#endif // ONELANCFORM_H
