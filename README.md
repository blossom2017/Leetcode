# Leetcode
Contains a script to automatically download accepted submissions in Leetcode and my accepted submissions in C++

## Steps to automatically download your submitted solutions
### Getting a list of accepted solutions
* We need to first login to our account manually using Chrome after which we can use the API provided by leetcode to download our accepted solutions.
* Leetcode provides an API where we can view the status of the problem solved in json format.

```
url = "https://leetcode.com/api/problems/all/"
```

* Looking at one of the stat-status pairs, we can get information on the problem id (frontend_question_id) and status (ac if accepted, null if not tried)

```
{
  "stat": {
    "question_id": 1724,
    "question__article__live": null,
    "question__article__slug": null,
    "question__title": "Customer Who Visited but Did Not Make Any Transactions",
    "question__title_slug": "customer-who-visited-but-did-not-make-any-transactions",
    "question__hide": false,
    "total_acs": 348,
    "total_submitted": 395,
    "frontend_question_id": 1581,
    "is_new_question": true
  },
  "status": null,
  "difficulty": {
    "level": 1
  },
  "paid_only": true,
  "is_favor": false,
  "frequency": 0,
  "progress": 0
}
```
### Automatically downloading accepted solutions via Leetcode-CLI

* After successful login to leetcode via Chrome, right click on the browser page and click Inspect Element-> Network. Open the leetcode api url in the first step and copy the values of cookie and user-agent from request headers in script.py.
* Run the python script script.py which will generate a shell script containing commands to download accepted solutions via Leetcode cli.
* Install and login in leetcode cli using the following commands.

```
npm install -g leetcode-cli
leetcode plugin -i cookie.chrome
brew install libsecret
# Login via chrome manually and then login via leetcode cli
leetcode user -l
# Enter your username and password
```
* Execute the shell script using the following commands

```
chmod +x get_ac.sh
./get_ac.sh
```
### References 
Documentation on Leetcode cli - https://skygragon.github.io/leetcode-cli/commands#session
