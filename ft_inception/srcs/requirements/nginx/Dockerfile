FROM debian:buster

RUN apt-get update -y && apt-get install -y \
  openssl \
  nginx

RUN openssl req -newkey rsa:2048 -x509 -sha256 -nodes -days 342 -out /etc/ssl/certs/aaguiler.crt -keyout /etc/ssl/private/aaguiler.key -subj "/C=ES/L=Malaga/CN=aaguiler.42.fr"

COPY ./config/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]