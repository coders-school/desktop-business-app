# Desktop Business Application

TBD...

## Development

### Prerequisites

- Docker
- Google Test
- C++20
- clang-format (recommended minimum ver. 17)

### Format code before committing manually

```bash
find . -name '*.cpp' -or -name '*.h' -or -name '*.hpp' | xargs clang-format --verbose -style=file -i
```

### Format code before committing using bash script

```bash
# run once after repo download if permission problem occurs
chmod +x ./clang-fmt-all.sh
# run from the top of workspace directory
./clang-fmt-all.sh
```


### Build

```bash
docker build -t desktop-business-application .
```

### Run image

```bash
docker run -it --entrypoint /bin/bash desktop-business-application
```

### Run GUI application from docker (on Ubuntu)

```bash
xhost +local:docker
docker run --net=host -e DISPLAY=$DISPLAY desktop-business-application
```
