# nonebot2安装教程
***首先要有python并且配置好环境***
## 安装nb-cli

首先在任何一个地方打开cmd（建议安装微软应用商店的 Windows Terminal）在窗口中输入
```bash
pip install nb-cli
```

## 安装[go-cqhttp](https://github.com/Mrs4s/go-cqhttp/)

下载后找到你想存放机器人的目录下新建文件夹`go-cqhttp`把下载好的gocq放进去，双击运行，按三次确定。

新建文本文件，填入以下内容，修改qq和密码

```yaml
account: # 账号相关
  uin: 123456789 # QQ账号
  password: '123456789' # 密码为空时使用扫码登录
  encrypt: false  # 是否开启密码加密
  status: 0      # 在线状态
  relogin:
    delay: 3
    interval: 3
    max-times: 0

  use-sso-address: true

heartbeat:
  interval: 5

message:
  post-format: string
  ignore-invalid-cqcode: false
  force-fragment: true
  fix-url: false
  proxy-rewrite: ''
  report-self-message: false
  remove-reply-at: false
  extra-reply-data: false
  skip-mime-scan: false

output:
  log-level: warn
  log-aging: 15
  log-force-new: true
  log-colorful: true
  debug: false

default-middlewares: &default
  access-token: ''
  filter: ''
  rate-limit:
    enabled: false
    frequency: 1
    bucket: 1

database:
  leveldb:
    enable: true
  cache:
    image: data/image.db
    video: data/video.db

servers:
  - ws-reverse:
      universal: ws://127.0.0.1:6660/onebot/v11/ws/
      reconnect-interval: 3000
      middlewares:
        <<: *default
```
然后将文件重命名为`config.yml`，然后运行`go-cqhttp.bat`，完成二维码登陆验证。(然后可以先忽略他)

## 创建nonebot2项目

在想要安装bot的目录打开`cmd`或`powershell`(如果你有`Windows Terminal`的话，可以`右键`,`在Windows终端打开`，没有的话可以打开cmd后通过`cd`切换目录)，注意命令提示符前应是你放`bot`的路径(比如说我的路径是`E:\github\bot\`,那么应显示为`E:\github\bot>`)

输入`nb create`，如果没有错误的话应该会出现

```bash
[?] Project Name: 
```

名字，随便填即可，这里以LittlePaimon为例

然后会有

```bash
[?] Where to store the plugin?
> In a "LittlePaimon" folder
> In a src folder
```

选择插件放置目录，键盘↑↓选择，回车确认，随便选

接下来是

```bash
[?] Which builtin plugin(s) would you like to user?
```

可以直接回车

然后

```bash
[?] which adapter(s) would you like to use?
>  ● OneBot V11
   o 钉钉
   o 飞书
   o Telegram
   o QQ 频道
   o 开黑啦
   o mirai2
```

选第一个，空格选中，回车确认

至此`Nonebot2`项目已创建成功

# 安装Nonebot2插件

这里以`LittlePaimon`为例

下载[`LittlePaimon`](https://github.com/CMHopeSunshine/LittlePaimon)

下载后在`bot`目录解压

在`bot`目录找到`.env`，把`dev`改为`prod`

编辑`.env.prod`，修改一下内容

```bash
HOST=127.0.0.1 # Nonebot监听的IP，如需外网访问，改为0.0.0.0
PORT=6660 # Nonebot监听的端口，和go-cqhttp的端口一致
LOG_LEVEL=INFO # 日志等级
SUPERUSERS=["123456"] # 超级用户
NICKNAME=["派蒙", "bot"] # 机器人的昵称
COMMAND_START=["", "/", "#"] # 命令前缀,根据需要自行修改
COMMAND_SEP=[""] # 命令分隔符，别动
```

安装`LittlePaimon`所需插件
```bash
nb plugin install nonebot-plugin-apscheduler
# 安装定时任务插件

pip install httpx xlsxwriter sqlitedict matplotlib aiofiles bs4
# 安装相关依赖
```
编辑`bot.py`
```python
# 在nonebot.load_from_toml下面添加这句，加载插件
nonebot.load_plugins("LittlePaimon")
```
至此插件已安装成功

## 运行bot
- 进入`go-cqhttp`目录双击运行`go-cqhttp.bat`
- 在`bot`目录打开`cmd`，输入`nb run`

**至此bot已成功运行**

# 配置`FFmpeg`和`Mongo`数据库
到此`bot`可以成功运行，但是现在小派蒙还不能发语音，关于如何配置`FFmpeg`,请自行百度(😀)

## 关于如何配置`Mongo`

[官网](https://www.mongodb.com/try/download/community)下载

安装

![img](https://img-blog.csdnimg.cn/3a81bfc6c9c949e1bdd3f3ca33a5f489.png)

勾选同意，点击next

![img](https://img-blog.csdnimg.cn/3a81bfc6c9c949e1bdd3f3ca33a5f489.png)

点击customer

![img](https://img-blog.csdnimg.cn/a800579b223c494aa49a59751495bc3c.png)

点击修改安装路径(你想要安装的路径)

![img](https://img-blog.csdnimg.cn/f1ba7ec80f104df6aae68d7f245a0eac.png)

点击next

![img](https://img-blog.csdnimg.cn/441dfc24e2d544b7a7cb1eb5dd46bae5.png)

***取消勾选，点击next(很重要)***

![img](https://img-blog.csdnimg.cn/dcfd662540a04db0ab15f1e2a76ef298.png)

点击install

![img](https://img-blog.csdnimg.cn/0198af82219845dfb252683016d88bf2.png)

安装完成之后

![img](https://img-blog.csdnimg.cn/32c9c21173f2476682a4b6badbb846e0.png)

然后**在`data`目录新建文件夹`db`**，在`log`目录下新建`mongodb.log`文件(如果有的话忽略)

内容
```bash
dbpath=D:\frontapplication\mongodb\data\db#数据库路径
#这里是你的安装路径！！！！！
logpath=D:\frontapplication\mongodb\log\mongodb.log#日志输出文件路径
#这里是你的安装路径！！！！！
logappend=true#错误日志采用追加模式

journal=true#启用日志文件，默认启用

quiet=true #过滤掉无用的日志信息，若需要调试使用请设置为false

port=27017 #端口号 默认为27017
```

至此数据库已安装成功

## 配置小派蒙插件
编辑`.env.prod`，加一行
```bash
paimon_mongodb_url=mongodb://127.0.0.1:27017/
```
(一般都是这个)

### 启动数据库
在安装`Mongo`的`bin`目录打开`cmd`，输入`mongod -dbpath D:\你安装Mongo的目录\data\db`

在安装`Mongo`的`bin`目录再打开一个`cmd`,输入`mongo`启动服务

至此数据库已安装成功

# 启动小派蒙

先打开`Mongo`，再启动`go-cqhttp`，再运行`nonebot2`，你的小派蒙就可以成功运行了！

