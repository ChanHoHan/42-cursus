#!/bin/bash

service mysql start
service php7.3-fpm start
service nginx start

if [ ${AUTOINDEX} -eq -1 ]; then
        sed -i 's/autoindex on;/autoindex off;/g' /etc/nginx/sites-available/default
fi
bash
