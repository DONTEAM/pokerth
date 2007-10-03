/***************************************************************************
 *   Copyright (C) 2006 by FThauer FHammer   *
 *   f.thauer@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef STARTNETWORKGAMEDIALOGIMPL_H
#define STARTNETWORKGAMEDIALOGIMPL_H

#include "ui_startnetworkgamedialog.h"

#include <QtGui>
#include <QtCore>
#include "sdlplayer.h"
#include "mainwindowimpl.h"

class Session;
class ConfigFile;

class startNetworkGameDialogImpl: public QDialog, public Ui::startNetworkGameDialog {
Q_OBJECT
public:
	startNetworkGameDialogImpl(QWidget *parent = 0, ConfigFile *config = 0);

	void setSession(Session *session);

public slots:

	void setMyW ( mainWindowImpl* theValue ) { myW = theValue; }
	

	void startGame();
	void cancel();
	void refresh(int actionID);
	void joinedNetworkGame(unsigned playerId, QString playerName, int rights);
	void addConnectedPlayer(unsigned playerId, QString playerName, int rights);
	void updatePlayer(unsigned playerId, QString newPlayerName);
	void removePlayer(unsigned playerId, QString playerName);
	void newGameAdmin(unsigned playerId, QString playerName);

	void playerSelected(QTreeWidgetItem*, QTreeWidgetItem*);
	void kickPlayer();
	void checkPlayerQuantity();
	void clearDialog();

	void keyPressEvent ( QKeyEvent*);

	void setMaxPlayerNumber ( int theValue ) { maxPlayerNumber = theValue; label_maxPlayerNumber->setText(QString::number(theValue,10)); }
	int getMaxPlayerNumber() const { return maxPlayerNumber; }

	void exec();

	void sendChatMessage();

private: 

	mainWindowImpl* myW;
	int maxPlayerNumber;
	unsigned myPlayerId;
	bool isAdmin;
	ConfigFile *myConfig;
	Session *mySession;
};

#endif
