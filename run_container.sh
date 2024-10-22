#!/bin/bash

docker start desktop-business-app
xhost +local:docker
docker exec -it desktop-business-app bash
