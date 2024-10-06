#!/bin/bash

# Build the Docker image
docker build -t desktop-business-app .

# Run the container in the background (detached mode)
docker run -d --name desktop-business-app -v $(pwd):/application -w /application desktop-business-app tail -f /dev/null
