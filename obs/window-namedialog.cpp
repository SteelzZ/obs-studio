/******************************************************************************
    Copyright (C) 2013 by Hugh Bailey <obs.jim@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include "window-namedialog.hpp"
#include "ui_NameDialog.h"
#include "obs-app.hpp"

using namespace std;

NameDialog::NameDialog(QWidget *parent)
	: QDialog (parent),
	  ui      (new Ui::NameDialog)
{
	ui->setupUi(this);

	installEventFilter(CreateShortcutFilter());
}

bool NameDialog::AskForName(QWidget *parent, const QString &title,
		const QString &text, string &str, const QString &placeHolder)
{
	NameDialog dialog(parent);
	dialog.setWindowTitle(title);
	dialog.ui->label->setText(text);
	dialog.ui->userText->setText(placeHolder);
	dialog.ui->userText->selectAll();

	bool accepted = (dialog.exec() == DialogCode::Accepted);
	if (accepted)
		str = dialog.ui->userText->text().toStdString();

	return accepted;
}
