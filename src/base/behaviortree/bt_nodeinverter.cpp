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
#include "bt_nodeinverter.h"

BT_NodeInverter::BT_NodeInverter( QString name, QVariantMap& blackboard ) :
	BT_Node( name, blackboard )
{
}

BT_NodeInverter::~BT_NodeInverter()
{
}

BT_RESULT BT_NodeInverter::tick()
{
	if ( m_children.size() > 0 )
	{
		BT_RESULT result = m_children[0]->tick();
		if ( result == BT_RESULT::RUNNING )
		{
			m_status = BT_RESULT::RUNNING;
			return m_status;
		}
		else if ( result == BT_RESULT::FAILURE )
		{
			m_status = BT_RESULT::SUCCESS;
			return m_status;
		}
	}
	m_status = BT_RESULT::FAILURE;
	return m_status;
}