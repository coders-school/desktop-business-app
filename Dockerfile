FROM ubuntu:mantic as BUILD
ENV PROJECT_NAME=desktop-business-app

WORKDIR /application
COPY . /application

RUN /application/dependencies.sh

RUN cmake -S . -B build && cmake --build build

RUN /application/bin/${PROJECT_NAME}-tests

FROM ubuntu:mantic as FINAL
ENV PROJECT_NAME=desktop-business-app

WORKDIR /application

COPY /dependencies.sh /application/
RUN /application/dependencies.sh

COPY --from=BUILD /application/bin/${PROJECT_NAME} /application/bin/${PROJECT_NAME}
COPY --from=BUILD /application/bin/${PROJECT_NAME}-tests /application/bin/${PROJECT_NAME}-tests

ENTRYPOINT /application/bin/${PROJECT_NAME}
