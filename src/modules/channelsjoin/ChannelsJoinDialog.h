#ifndef _CHANNELSJOIN_H_
#define _CHANNELSJOIN_H_
//=============================================================================
//
//   File : ChannelsJoinDialog.h
//   Creation date : Thu Nov 06 2001 12:30:25 CEST by Juan Alvarez
//
//   This file is part of the KVIrc irc client distribution
//   Copyright (C) 2001-2010 Szymon Stefanek (pragma at kvirc dot net)
//
//   This program is FREE software. You can redistribute it and/or
//   modify it under the terms of the GNU General Public License
//   as published by the Free Software Foundation; either version 2
//   of the License, or (at your opinion) any later version.
//
//   This program is distributed in the HOPE that it will be USEFUL,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//   See the GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program. If not, write to the Free Software Foundation,
//   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
//
//=============================================================================

/**
* \file ChannelsJoinDialog.h
* \author Juan Alvarez
* \brief Channels join window
*/

#include "KviWindow.h"
#include "KviCString.h"
#include <QTreeWidget>

#include <QDialog>

class QCheckBox;
class QPushButton;
class QLineEdit;
class KviConsoleWindow;
class KviTalGroupBox;

/**
* \class ChannelsJoinDialog
* \brief Channels join window class
*/
class ChannelsJoinDialog : public QDialog
{
	Q_OBJECT
public:
	/**
	* \brief Constructs the channels join window
	* \param par The parent widget
	* \param name The name of the window
	* \return ChannelsJoinDialog
	*/
	ChannelsJoinDialog(QWidget * par, const char * name);

	/**
	* \brief Destroys the channels join window
	*/
	~ChannelsJoinDialog();
protected:
	QLineEdit        * m_pChannelEdit;
	QTreeWidget * m_pTreeWidget;
	KviTalGroupBox   * m_pGroupBox;
	QLineEdit        * m_pPass;
	QCheckBox        * m_pShowAtStartupCheck;
	QCheckBox        * m_pCloseAfterJoinCheck;
	QPushButton      * m_pJoinButton;
	QPushButton      * m_pRegButton;
	QPushButton      * m_pClearButton;
	KviConsoleWindow       * m_pConsole;
public:
	virtual void closeEvent(QCloseEvent * e);

	/**
	* \brief Fills in the servers' list
	* \return void
	*/
	void fillListView();

	/**
	* \brief Enables join and register button if channel is found
	* \return void
	*/
	void enableJoin();

	/**
	* \brief Sets the console and fills in the servers' list
	* \param pConsole The source console
	* \return void
	*/
	void setConsole(KviConsoleWindow * pConsole);
protected slots:
	/**
	* \brief Called when the text changes
	* \return void
	*/
	void editTextChanged(const QString &);

	/**
	* \brief Called when an item is clicked
	* \param it The item clicked
	* \return void
	*/
	void itemClicked(QTreeWidgetItem * it, int);

	/**
	* \brief Called when an item is double-clicked
	* \param it The item clicked
	* \return void
	*/
	void itemDoubleClicked(QTreeWidgetItem * it, int);

	/**
	* \brief Called when the return is pressed
	*
	* It joins the selected channel
	* \return void
	*/
	void editReturnPressed();

	/**
	* \brief Called when the cancel button is pressed
	*
	* It destroys the window object
	* \return void
	*/
	void cancelClicked();

	/**
	* \brief Called when the join button is pressed
	*
	* It joins the selected channel
	* \return void
	*/
	void joinClicked();

	/**
	* \brief Called when the register button is pressed
	*
	* It registers the selected channel in the database
	* \return void
	*/
	void regClicked();

	/**
	* \brief Called when the clear button is pressed
	*
	* It clears the list of recent channels
	* \return void
	*/
	void clearClicked();

	//void whoClicked();
	//void namesClicked();
};

#endif //_CHANNELSJOINSWINDOW_H_