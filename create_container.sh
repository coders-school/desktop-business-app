# Run ONCE to create container

#!/bin/bash
docker build -t desktop-business-app .
docker run --name desktop-business-app-container -it --net=host -e DISPLAY=$DISPLAY desktop-business-app
