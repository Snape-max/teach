import requests as rq 
import time

url = "https://pixiv.cat/"
ans = 1
num = 0
while num != "exit":
    num = input("id: ")
    if num != "exit":
        x = rq.get(url+num+".png").content
        name = str(time.time())[:11]
        a = open("pic-down/pic/"+num+".png","wb")
        a.write(x)
        a.close()
    else:
        print("Thank for using")
