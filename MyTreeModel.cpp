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

#include "MyTreeModel.hpp"

using namespace TreeModels;

MyTreeModel::MyTreeModel(QObject *parent) :
    QStandardItemModel(parent)
{
    fillReles();

}

void MyTreeModel::fillReles()
{
    m_roleNameMapping[Role_Name] = name_role_txt;
    m_roleNameMapping[Role_Description] = description_role_txt;
    m_roleNameMapping[Role_GlobalType] = global_type_role_txt;
    m_roleNameMapping[Role_Acces] = acces_role_txt;
    m_roleNameMapping[Role_ValueType] = value_type_role_txt;
    m_roleNameMapping[Role_FunctionRetType] = function_ret_type_role_txt;
    m_roleNameMapping[Role_FunctionInputPar] = function_input_par_role_txt;

    m_tableRolesList.push_back(QByteArray(name_role_txt));
    m_tableRolesList.push_back(QByteArray(description_role_txt));
    m_tableRolesList.push_back(QByteArray(global_type_role_txt));
    m_tableRolesList.push_back(QByteArray(acces_role_txt));
    m_tableRolesList.push_back(QByteArray(value_type_role_txt));
    m_tableRolesList.push_back(QByteArray(function_ret_type_role_txt));
    m_tableRolesList.push_back(QByteArray(function_input_par_role_txt));

    m_tableNameList.push_back(QByteArray("Name"));
    m_tableNameList.push_back(QByteArray("Description"));
    m_tableNameList.push_back(QByteArray("Global Type"));
    m_tableNameList.push_back(QByteArray("Acces"));
    m_tableNameList.push_back(QByteArray("Value Type"));
    m_tableNameList.push_back(QByteArray("Function Ret Type"));
    m_tableNameList.push_back(QByteArray("Function input Par"));
}

QHash<int, QByteArray> MyTreeModel::roleNames() const
{
    return m_roleNameMapping;
}

QByteArray MyTreeModel::getRole(int tablePos) const
{
    if(tablePos < m_tableRolesList.count()) {
        return m_tableRolesList.at(tablePos);
    }

    return QByteArray("");
}

QByteArray MyTreeModel::getTableName(int tablePos) const
{
    if(tablePos < m_tableNameList.count()) {
        return m_tableNameList.at(tablePos);
    }

    return QByteArray("");
}

int MyTreeModel::getColumns() const
{
    return m_tableRolesList.count();
}

void MyTreeModel::BuildTree(const QMap<QString, ClangParser::Class> &classes)
{
    for (auto it = classes.begin(); it != classes.end(); ++it) {
        auto ClassEntry = new QStandardItem(it.key());
        //qDebug() << "Class:" << it.key() << "is struct:" << it.value().isStruct;
        if(it.value().isStruct) {
            ClassEntry->setData( "struct", Role_Description );
            ClassEntry->setData( "s", Role_GlobalType );
        } else {
            ClassEntry->setData( "class", Role_Description );
            ClassEntry->setData( "c", Role_GlobalType );
        }

        ClassEntry->setData( ClangParser::accessSpecifierToString(it.value().accessSpecifier), Role_Acces );
        ClassEntry->setData( it.value().name, Role_ValueType );

        // variables for -------------------------------------------------------------------------------------------------------------------------------------
        for (const auto &var : it.value().variables) {
            //qDebug() << "  Variable:" << var.name << "Type:" << var.type << "Access:" << ClangParser::accessSpecifierToString(var.accessSpecifier);
            auto VariableEntry = new QStandardItem(var.name);
            VariableEntry->setData( "variable", Role_Description );
            VariableEntry->setData( "v", Role_GlobalType );
            VariableEntry->setData( ClangParser::accessSpecifierToString(var.accessSpecifier), Role_Acces );
            VariableEntry->setData( var.type, Role_ValueType );
            ClassEntry->appendRow(VariableEntry);
        }

        // functions for -------------------------------------------------------------------------------------------------------------------------------------
        for (const auto &func : it.value().functions) {
            //qDebug() << "  Function:" << func.name << "Return Type:" << func.returnType << "Parameters:" << func.parameters << "Access:" << ClangParser::accessSpecifierToString(func.accessSpecifier);
            auto FunctionEntry = new QStandardItem(func.name);
            FunctionEntry->setData( "function", Role_Description );
            FunctionEntry->setData( "f", Role_GlobalType );
            FunctionEntry->setData( ClangParser::accessSpecifierToString(func.accessSpecifier), Role_Acces );
            FunctionEntry->setData( func.returnType, Role_FunctionRetType );

            // parse parameters -------------------------------------------------------------------------------------------------------------------------------------
            QString funcParams("(");
            if(func.parameters.count() == 0) {
                funcParams.append("void");
            } else {
                for (const auto &param : func.parameters) {
                    funcParams.append(param);
                    if(func.parameters.last().data() != param.data()) {
                        funcParams.append(", ");
                    }
                }
            }
            funcParams.append(")");
            // ------------------------------------------------------------------------------------------------------------------------------------------------------

            FunctionEntry->setData( funcParams, Role_FunctionInputPar );
            ClassEntry->appendRow(FunctionEntry);
        }

        this->appendRow( ClassEntry );
    }
}
