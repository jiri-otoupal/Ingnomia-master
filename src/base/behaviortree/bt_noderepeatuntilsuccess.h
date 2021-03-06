/*	
	This file is part of Ingnomia https://github.com/rschurade/Ingnomia
    Copyright (C) 2017-2020  Ralph Schurade, Ingnomia Team

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include "bt_node.h"

class BT_NodeRepeatUntilSuccess final : public BT_Node
{
public:
	BT_NodeRepeatUntilSuccess( QString name, int num, QVariantMap& blackboard );
	~BT_NodeRepeatUntilSuccess();

	QVariantMap serialize();
	void deserialize( QVariantMap in );

	BT_RESULT tick();

private:
	int m_num = 0;
};
