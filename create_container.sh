
# Run ONCE to create container

#!/bin/bash
docker build -t desktop-business-app .

# Run the container in the background (detached mode)
docker run -d --name desktop-business-app --net=host -e DISPLAY=$DISPLAY -v $(pwd):/application -w /application desktop-business-app tail -f /dev/null
