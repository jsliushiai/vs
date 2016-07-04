# vs
	vc++自学练习代码
#step1
	winodws install git
#step2
	git shell create id_rsa and id_rsa.pub
	ssh-keygen -t rsa -C "xxxx@xxx.com" 一路next
#step3
	add id_rsa.pub github---SSH keys
#step4 
	github create a Repository
#step5
	git config --global user.name "xxx"
	git config --global user.email "xxxx@xxx.com"
	
	已存在的文件夹或 Git 仓库
	cd existing_folder
	git init
	git remote add origin git@github.com:xxxx/vxxxx.git
	git add .
	git commit
	git push -u origin master
	
	创建新版本库
	git clone git@github.com:xxxx/vxxxx.git
	cd existing_folder
	touch README.md
	git add README.md
	git commit -m "add README"
	git push -u origin master