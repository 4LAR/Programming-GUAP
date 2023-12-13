# Dockerfile
FROM openjdk:17

RUN mkdir -p /usr/src/myapp
COPY target/app.jar /usr/src/myapp
RUN mkdir -p /usr/src/myapp/target
COPY target/keystore.p12 /usr/src/myapp/target
WORKDIR /usr/src/myapp
ENTRYPOINT ["java", "-jar","app.jar"]
