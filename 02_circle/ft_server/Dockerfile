FROM	debian:buster
LABEL	maintainer="chan@student.42seoul.kr"

ENV	AUTOINDEX on

RUN	apt-get update && apt-get install -y \
	    nginx \
	    mariadb-server \
	    php-mysql \
	    php-mbstring \
	    openssl \
	    vim \
	    wget \
	    php7.3-fpm

COPY	./srcs/run.sh /
COPY	./srcs/default /
COPY	./srcs/wp-config.php /
COPY	./srcs/config.inc.php /

RUN rm /etc/nginx/sites-enabled/default
RUN mv /default /etc/nginx/sites-available/

#ssl
RUN	openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/ O=42Seoul/OU=chan/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt &&\
cp /localhost.dev.crt /etc/ssl/certs &&\
cp /localhost.dev.key /etc/ssl/private &&\
chmod 600 /etc/ssl/certs/localhost.dev.crt /etc/ssl/private/localhost.dev.key

#phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz &&\
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz &&\
mv phpMyAdmin-5.0.2-all-languages phpmyadmin &&\
mv /phpmyadmin /var/www/html &&\
cp /config.inc.php /var/www/html/phpmyadmin

#wordpress
RUN wget https://wordpress.org/latest.tar.gz &&\
tar -xvf latest.tar.gz &&\
mv /wordpress /var/www/html &&\
chown -R www-data:www-data /var/www/html/wordpress &&\
cp /wp-config.php /var/www/html/wordpress

#db
RUN service mysql start &&\
mysql -e "CREATE USER IF NOT EXISTS 'chan'@'localhost' IDENTIFIED BY 'chan';" && \
mysql -e "CREATE DATABASE IF NOT EXISTS phpmyadmin;" && \
mysql -e "CREATE DATABASE IF NOT EXISTS wordpress;" && \
mysql -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'chan'@'localhost' WITH GRANT OPTION;"

EXPOSE	80 443

CMD bash run.sh
#ENTRYPOINT ["bash", "run.sh"]
