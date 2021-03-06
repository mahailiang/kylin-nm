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

#include "loadingdiv.h"

LoadingDiv::LoadingDiv(QWidget *parent) : QWidget(parent)
{
    this->resize(480, 500);

    this->loadingGif = new QLabel(this);
    this->loadingGif->resize(96, 96);
    this->loadingGif->move(this->width() / 2 - 96 / 2 + 20, this->height() / 2 - 96 / 2);
    this->loadingGif->show();


    this->switchTimer = new QTimer(this);
    connect(switchTimer, SIGNAL(timeout()), this, SLOT(switchAnimStep()));

    this->raise();
    this->hide();
}

void LoadingDiv::switchAnimStep(){
    QString qpmQss = "QLabel{background-image:url(':/res/s/conning-b/";
    qpmQss.append(QString::number(this->currentPage));
    qpmQss.append(".png');}");
    loadingGif->setStyleSheet(qpmQss);

    this->currentPage --;

    if(this->currentPage < 1){
        this->currentPage = 12;
    }
}

void LoadingDiv::startLoading(){
    this->currentPage = 12;
    this->switchTimer->start(60);
    this->show();
}

void LoadingDiv::stopLoading(){
    this->switchTimer->stop();
    this->hide();
}
