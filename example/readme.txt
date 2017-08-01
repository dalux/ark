##示例单入口框架程序结构

nginx 配置:

server {

    listen 80;
    server_name index.localhost;
    index index.php;
    root  ~/ark/example/public;

    location / {
        if (!-e $request_filename) {
            rewrite "^(.*)$" /index.php last;
        }
    }

    location ~ \.php {
        fastcgi_pass   127.0.0.1:9000;
        fastcgi_index  index.php;
        include        fastcgi.conf;
    }

}

该demo请求URL类似：http://index.localhost/user/panel

对应具体的控制器：~/ark/example/logic/index/Controller/User/Panel.php
对应具体的类名：\App\Controller\User\Panel()
