/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef CORE_H
#define CORE_H

#include "thread"
#include "functional"

#include "Domain/CompetitionEnum.h"
#include "Factories/FieldDrawerFactory.h"
#include "Robots/RobotDrawer.h"
#include "Communications/StateReceiver.h"
#include "Cameras/TvCamera.h"
#include "World.h"

class Core {
private:

	bool paused;
	int argc;
	char **argv;
	Pose ball;
	std::vector<Pose> robots;
	string receiveStateAddress;
	thread *worldThread;
	thread *receiveStateThread;

public:

	Core( int argc, char **argv );
	void init();
	void worldThreadWrapper();
	void receiveStateThreadWrapper();
};

#endif // CORE_H