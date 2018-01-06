/**************************************************************************
 *  This file is part of QXmlEdit                                         *
 *  Copyright (C) 2015-2018 by Luca Bellonda and individual contributors  *
 *    as indicated in the AUTHORS file                                    *
 *  lbellonda _at_ gmail.com                                              *
 *                                                                        *
 * This library is free software; you can redistribute it and/or          *
 * modify it under the terms of the GNU Library General Public            *
 * License as published by the Free Software Foundation; either           *
 * version 2 of the License, or (at your option) any later version.       *
 *                                                                        *
 * This library is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      *
 * Library General Public License for more details.                       *
 *                                                                        *
 * You should have received a copy of the GNU Library General Public      *
 * License along with this library; if not, write to the                  *
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,       *
 * Boston, MA  02110-1301  USA                                            *
 **************************************************************************/


#ifndef NAMESPACEREFERENCEENTRY_H
#define NAMESPACEREFERENCEENTRY_H

#include    "xmlEdit.h"
#include "libQXmlEdit_global.h"

class LIBQXMLEDITSHARED_EXPORT SingleNamespaceReferenceEntry
{
    QString _uri;
    QString _schemaLocation;
public:
    SingleNamespaceReferenceEntry();
    SingleNamespaceReferenceEntry(const QString &uri, const QString &location);
    ~SingleNamespaceReferenceEntry();
    //--
    QString uri() const;
    void setUri(const QString &uri);
    QString schemaLocation() const;
    void setSchemaLocation(const QString &schemaLocation);
};

class LIBQXMLEDITSHARED_EXPORT NamespaceReferenceEntry
{
    bool _useNoNamespaceSchemaLocation;
    QString _noNamespaceSchemaLocation;
    QList<SingleNamespaceReferenceEntry*> _references;
    //---
    void reset();

public:
    NamespaceReferenceEntry();
    NamespaceReferenceEntry(const QString &noNsRef);
    ~NamespaceReferenceEntry();
    bool isUseNoNamespaceSchemaLocation() const;
    void setUseNoNamespaceSchemaLocation(const bool useNoNamespaceSchemaLocation);
    /*!
     * \brief setUseNoNamespaceSchemaLocation: commodity method to set related properties
     * \param value
     * \param noNamespaceSchemaLocation
     */
    void setUseNoNamespaceSchemaLocation(const bool value, const QString &noNamespaceSchemaLocation);
    QString noNamespaceSchemaLocation() const;
    void setNoNamespaceSchemaLocation(const QString &noNamespaceSchemaLocation);
    QList<SingleNamespaceReferenceEntry *> references() const;
    void setReferences(const QList<SingleNamespaceReferenceEntry *> &references);

    void addSchemaReference(const QString &uri, const QString &location);
    bool compareTo(NamespaceReferenceEntry * other);
    QString toString();
};

#endif // NAMESPACEREFERENCEENTRY_H
