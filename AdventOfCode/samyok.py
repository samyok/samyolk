import os
import re
import http.cookiejar
import urllib.request
from bs4 import BeautifulSoup
import time


def parseCookieFile(cookiefile):
    cookies = http.cookiejar.MozillaCookieJar()
    cookies.load(cookiefile, ignore_discard=True, ignore_expires=True)
    return cookies


def rl(arr):
    return range(len(arr))


def coerce(types, item, delim=" "):
    return [t(i) for t, i in zip(types, re.split(delim, item))]


def lmap(_lambda, arr):
    return list(map(_lambda, arr))


def lcoerce(pattern, _list, delim=" "):
    return lmap(lambda item: coerce(pattern, item, delim), _list)


def distance(a, b):
    return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2


def extract_ints(string, delim=" "):
    arr = re.split(delim, string)
    res = []
    for item in arr:
        try:
            res.append(int(item))
        except ValueError:
            pass
    return res


def submit(year, day, level, ans):
    print(ans)
    prompt = f"Submit {ans} for {year}/day-{day}/level-{level}? [y/N] "

    path = os.path.dirname(os.path.realpath(__file__))
    if input(prompt).lower() != "y":
        return

    # see if cache time exist in last_submit.txt
    # if it does, wait until that 60 seconds after that time has passed
    last_submit_path = path + "/last_submit.txt"
    if os.path.exists(last_submit_path):
        with open(last_submit_path, "r") as file:
            last_submit = file.read().strip()
            if last_submit != "":
                last_submit = float(last_submit)
                if time.time() - last_submit < 60:
                    # wait until 60 seconds after last_submit
                    print("Waiting {} seconds before submitting...".format(60 - round(time.time() - last_submit)))
                    time.sleep(60 - (time.time() - last_submit))

    cookie_path = path + "/cookies.txt"
    cookies = parseCookieFile(cookie_path)
    session = ""

    for cookie in cookies:
        if cookie.name == "session":
            session = cookie.value

    url = "https://adventofcode.com/{}/day/{}/answer".format(year, day)
    data = "level={}&answer={}".format(level, ans)
    headers = {
        "Cookie": "session={}".format(session),
        "Content-Type": "application/x-www-form-urlencoded",
    }
    req = urllib.request.Request(url, data.encode("utf-8"), headers)
    with urllib.request.urlopen(req) as response:
        html = response.read().decode("utf-8")
        soup = BeautifulSoup(html, features="html.parser")
        print(soup.find("main").text)
        with open(last_submit_path, "w") as file:
            file.write("0.0" if "got rank" in soup.find("main").text else str(time.time()))

        if "got rank" in soup.find("main").text:
            # open chrome with link to problem:
            os.system(
                "open https://adventofcode.com/{}/day/{}#:~:text=puzzle%20input.-,Answer%3A,-%5BSubmit%5D".format(year,
                                                                                                                  day))
