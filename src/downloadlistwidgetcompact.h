/*
Copyright (C) 2012 Sebastian Herbord. All rights reserved.

This file is part of Mod Organizer.

Mod Organizer is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Mod Organizer is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Mod Organizer.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DOWNLOADLISTWIDGETCOMPACT_H
#define DOWNLOADLISTWIDGETCOMPACT_H

#include <QWidget>
#include <QItemDelegate>
#include <QLabel>
#include <QProgressBar>
#include <QTreeView>


namespace Ui {
class DownloadListWidgetCompact;
}

class DownloadListWidgetCompact : public QWidget
{
  Q_OBJECT
  
public:
  explicit DownloadListWidgetCompact(QWidget *parent = 0);
  ~DownloadListWidgetCompact();

private:
  Ui::DownloadListWidgetCompact *ui;
  int m_ContextRow;
};

class DownloadManager;

class DownloadListWidgetCompactDelegate : public QItemDelegate
{

  Q_OBJECT

public:

  DownloadListWidgetCompactDelegate(DownloadManager *manager, QTreeView *view, QObject *parent = 0);
  ~DownloadListWidgetCompactDelegate();

  virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:

  void installDownload(int index);
  void queryInfo(int index);
  void removeDownload(int index, bool deleteFile);
  void cancelDownload(int index);
  void pauseDownload(int index);
  void resumeDownload(int index);

protected:

  bool editorEvent(QEvent *event, QAbstractItemModel *model,
                   const QStyleOptionViewItem &option, const QModelIndex &index);

private slots:

  void issueInstall();
  void issueDelete();
  void issueRemoveFromView();
  void issueCancel();
  void issuePause();
  void issueResume();
  void issueDeleteAll();
  void issueDeleteCompleted();
  void issueRemoveFromViewAll();
  void issueRemoveFromViewCompleted();
  void issueQueryInfo();

private:

  DownloadListWidgetCompact *m_ItemWidget;
  DownloadManager *m_Manager;

  QLabel *m_NameLabel;
  QProgressBar *m_Progress;
  QLabel *m_DoneLabel;

  QModelIndex m_ContextIndex;

  QTreeView *m_View;

};

#endif // DOWNLOADLISTWIDGETCOMPACT_H
