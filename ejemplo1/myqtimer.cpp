/*
 * Copyright 2015 <copyright holder> <email>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#include "myqtimer.h"

MyQTimer::MyQTimer(QMutex* m_): QThread()
{
	control=m_;
}

void MyQTimer::setseg(int seg)
{
	control->lock();
	mseg=seg;
	control->unlock();
}
void MyQTimer::run()
{
	while(1){
	      control->lock();
	      int aux=mseg;
	      control->unlock();
	      msleep(aux);
	      emit senal();
	}
}

