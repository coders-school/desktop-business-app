# Desktop Business Application

TBD...

## Development

### Prerequisites

- Docker
- Google Test
- C++20

### Build

```bash
docker build -t desktop-business-application .
```

### Run image

```bash
docker run -it --entrypoint /bin/bash desktop-business-application
```

### Run GUI application from docker

```bash
xhost +local:docker
docker run --net=host -e DISPLAY=$DISPLAY desktop-business-application
```