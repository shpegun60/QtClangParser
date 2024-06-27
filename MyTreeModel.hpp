/*
 * Copyright 2015 ImaginativeThinking
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MYTREEMODEL_HPP
#define MYTREEMODEL_HPP

#include "qqml.h"
#include <QStandardItemModel>

#include <ClangParser.h>

namespace TreeModels
{
    class MyTreeModel : public QStandardItemModel
    {
        Q_OBJECT
        QML_ELEMENT
    public:
        explicit MyTreeModel(QObject *parent = 0);
        virtual ~MyTreeModel() = default;

        enum MyTreeModel_Roles
        {
            // Generic
            Role_Name = Qt::DisplayRole,
            Role_Description = Qt::WhatsThisRole,
            Role_GlobalType = Qt::UserRole+1,
            Role_Acces = Qt::UserRole+2,

            // value
            Role_ValueType = Qt::UserRole+3,
            // function
            Role_FunctionRetType = Qt::UserRole+4,
            Role_FunctionInputPar = Qt::UserRole+5
        };

        QHash<int, QByteArray> roleNames() const override;
        Q_INVOKABLE QByteArray getRole(int tablePos) const;
        Q_INVOKABLE QByteArray getTableName(int tablePos) const;
        Q_INVOKABLE int getColumns() const;
        void BuildTree(const QMap<QString, ClangParser::Class>& classes);

    private:
        void addEntry( const QString& name, const QString& type, const QString& description );

    private:
        QStandardItem* getBranch( const QString& branchName );
        void fillReles();


        int num = 0;
        static constexpr char name_role_txt[] = "name_role";
        static constexpr char description_role_txt[] = "description_role";
        static constexpr char global_type_role_txt[] = "global_type_role";
        static constexpr char acces_role_txt[] = "acces_role";
        static constexpr char value_type_role_txt[] = "value_type_role";
        static constexpr char function_ret_type_role_txt[] = "function_ret_type_role";
        static constexpr char function_input_par_role_txt[] = "function_input_par_role";


        QList<QByteArray> m_tableRolesList;
        QList<QByteArray> m_tableNameList;
        QHash<int, QByteArray> m_roleNameMapping;
    };
}

#endif // MYTREEMODEL_HPP
