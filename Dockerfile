FROM ubuntu:mantic as BUILD
ENV PROJECT_NAME=desktop-business-app

RUN apt update -y && \
    apt install -y libgtest-dev cmake make g++ && \
    apt install -y qt6-base-dev && \
    apt install -y libgl1-mesa-dev

WORKDIR /application
COPY . /application

RUN cmake -S . -B build && cmake --build build

RUN /application/bin/${PROJECT_NAME}-ut
RUN /application/bin/${PROJECT_NAME}-material_test

FROM ubuntu:mantic as FINAL
ENV PROJECT_NAME=desktop-business-app

RUN apt update -y && \
    apt install -y libgtest-dev cmake make g++&& \
    apt install -y qt6-base-dev

WORKDIR /application
COPY --from=BUILD /application/bin/${PROJECT_NAME} /application/bin/${PROJECT_NAME}
COPY --from=BUILD /application/bin/${PROJECT_NAME}-ut /application/bin/${PROJECT_NAME}-ut
COPY --from=BUILD /application/bin/${PROJECT_NAME}-material_test /application/bin/${PROJECT_NAME}-material_test

ENTRYPOINT /application/bin/${PROJECT_NAME}
