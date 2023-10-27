FROM	debian:buster

RUN apt-get update -y && apt-get install -y curl \
  php7.3-fpm \
  php7.3-mysql \
  php7.3-curl \
  php7.3-xml \
  php7.3-mbstring \
  php7.3-zip

COPY ./tools/script.sh /script.sh
COPY	./config/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf

RUN useradd wpuser && groupadd wpgroup && usermod -aG wpgroup wpuser
RUN chmod +x /script.sh

EXPOSE 9000

CMD ["/script.sh"]