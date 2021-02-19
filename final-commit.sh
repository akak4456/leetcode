git add .
if [ $# -eq 2 ];
then
	git commit -m "$2" # 만약에 -m을 입력했다면 즉 커밋 메시지를 입력했다면
else
	git commit -m "no message"
fi
git push origin master
