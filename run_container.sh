#!/bin/bash
docker start desktop-business-app-container
xhost +local:docker
docker exec -it desktop-business-app-container bash