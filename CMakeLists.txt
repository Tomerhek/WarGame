cmake_minimum_required(VERSION 3.8)
project(WarGame)

set(CMAKE_CXX_STANDARD 11)

add_executable(WarGame main.cpp Soldier.cpp Soldier.h Trooper.cpp Trooper.h Sniper.cpp Sniper.h Medic.cpp Medic.h Weapon.cpp Weapon.h Point2d.cpp Point2d.h M16.cpp M16.h UZI.cpp UZI.h Missile.cpp Missile.h Protection.cpp Protection.h BodyArmor.cpp BodyArmor.h ShieldArmor.cpp ShieldArmor.h Tree.cpp Tree.h Obstacle.cpp Obstacle.h Game.cpp Game.h Collectable.cpp Collectable.h Player.cpp Player.h Strategy.cpp Strategy.h Human.cpp Human.h Computer.cpp Computer.h fileParsing.cpp fileParsing.h FileControl.cpp FileControl.h)