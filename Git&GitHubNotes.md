## Why Git? (Basically this is BackEnd)
- Saving the history of a project.
- In group based projects, which person made which change and where in the project.

## Why GitHub? (And this is FrontEnd/GUI of the Git)
- It's an online platform/website that allows us to host our repositories.
(Repository is just a folder where all changes are saved)

## What is terminal?
- It helps us to manipulate file structure using set of commands.

## Linux Commands
1. ls command: list all the files in current folder.
<img width="445" alt="image" src="https://user-images.githubusercontent.com/92745924/155069740-34d7660e-8315-4cac-87d3-37cdbca40b09.png">

2. cd command: change the directory and move inside the folder
3. mkdir command: make a new folder.
<img width="284" alt="image" src="https://user-images.githubusercontent.com/92745924/155069989-680cce05-a49e-4f61-8bae-0f07969351d1.png">

4. git init command: The maintainence of entire history of git is done in a repository which is provided to us by Git. This is a Git Repository named as .git(. means hidden file). git init command gives us this.
5. ls -a: This gives all the hidden files.
6. ls .git: Tells us what is there inside this git folder.
<img width="424" alt="image" src="https://user-images.githubusercontent.com/92745924/155070196-5111bff8-ca60-4353-9162-c0466d7cdd9f.png">

7. touch command: It helps us to create a file.
<img width="371" alt="image" src="https://user-images.githubusercontent.com/92745924/155070358-f065399e-7819-41e4-978b-e94540c22809.png">

8. git status command: How do we see what all files are added/deleted 
<img width="515" alt="image" src="https://user-images.githubusercontent.com/92745924/155070457-615aa23a-befd-45cb-8e84-e5faf66c17b7.png">

9. git add .(for all files)/file name: Let's suppose we have gone to a wedding, the guests whose photo have not been taken by the photographer are untracked files, we need to take photos of these guests/files so that to save them in photo album/git repository, so to bring them on stage we use this command.
10. git commit -m "message": This step denotes that we have taken the picture.
<img width="364" alt="image" src="https://user-images.githubusercontent.com/92745924/155070590-2a029d51-55aa-44f4-8f4b-fd91bc3dc374.png">

11. Vim is the text editor of choice for many users that spend a lot of time on the command line. 
Unlike other editors, Vim has several modes of operation, which can be a little intimidating for new users.
Vim or its precursor Vi comes preinstalled on macOS and almost all Linux distributions. 
Knowing the basics of Vim will help you when you encounter a situation where your favorite editor is not available.
Commands:
- To Open a file: vim file.text
- The command to save a file in Vim is :w.
- To save the file without exiting the editor, switch back to normal mode by pressing Esc, type :w and hit Enter. 
- :x -> to save and exit
<img width="417" alt="image" src="https://user-images.githubusercontent.com/92745924/155071045-591b1edd-ed5c-46d2-8471-451fa09fb4aa.png">
<img width="467" alt="image" src="https://user-images.githubusercontent.com/92745924/155073445-67db6edd-fb9f-4a87-b629-a3c029354cf5.png">


12. cat file name: Gives a display whatever things are there in the file.
<img width="422" alt="image" src="https://user-images.githubusercontent.com/92745924/155071122-1299610e-aaa3-49e0-9b57-649685cfca78.png">

13. git restore --staged filename: To remove the files/guests from the stage before commit.
<img width="446" alt="image" src="https://user-images.githubusercontent.com/92745924/155071383-6063a70b-bb7c-4b42-a855-6fc78b0c9b9c.png">

14. git commit -m "message": To take a picture
<img width="347" alt="image" src="https://user-images.githubusercontent.com/92745924/155071534-8ae85b0f-2bb1-4b6b-83d5-6890aaa57ef1.png">

15. git log: Helps to see all the commits.
<img width="488" alt="image" src="https://user-images.githubusercontent.com/92745924/155071823-5a2fdb66-2177-4297-9ed6-5550f6ceffd4.png">

16. rm -rf filename: To delete the file.
<img width="445" alt="image" src="https://user-images.githubusercontent.com/92745924/155072449-0e598e44-a6a4-46b7-9611-1f1703a0fb1b.png">

17. git reset copyID: the ID that u'll copy, all the commits above it will be deleted.
The photographs that were taken are now deleted and they are back to unstage area.
<img width="440" alt="image" src="https://user-images.githubusercontent.com/92745924/155072537-fa5cf144-48ab-4038-b8a4-7d8a851543ea.png">

18. Stashing Changes:
For example, I want to save all my work somewhere else without making the history of the project, 
git stash is the command for that.
- First bring the people on stage-> git add. -> git status -> git stash (Hey Listen go back to back-stage area, whenever I want you, I'll bring you back!)
- I don't want to commit it and also I don't want to loose these changes!
- Popping from stash:Bringing back those changes that we stashed previously!
git stash pop command 
- Clean those changes that were not commited and were stashed:
git stash clear command
<img width="680" alt="image" src="https://user-images.githubusercontent.com/92745924/155076749-483c7c4e-9099-49f1-940e-546b988d3a6e.png">
<img width="670" alt="image" src="https://user-images.githubusercontent.com/92745924/155076807-64a2cd7f-6284-437b-8cd6-f60bc661734c.png">

19. Repository's link in GitHub, I wan't to attach it to the local project(Connecting remote repository to local repository) :
- git remote add origin URL
<img width="488" alt="image" src="https://user-images.githubusercontent.com/92745924/155078671-0ec89a15-fbdb-4d40-9813-823cc4c69b2e.png">
20. You want to push the changes from local to the remote repository at GitHub 
- git push origin master
<img width="404" alt="image" src="https://user-images.githubusercontent.com/92745924/155079040-accb2ae4-4dc1-4d6f-9296-7496f3b9cd6f.png">
<img width="960" alt="image" src="https://user-images.githubusercontent.com/92745924/155079282-09c56297-ae68-4e54-9a5e-6e2ea916f6a6.png">

## Branches
- Master is now known as main branch.
<img width="960" alt="image" src="https://user-images.githubusercontent.com/92745924/155081510-c16fdaf4-5618-4d48-a5e8-3dc75e83ce1e.png">
<img width="436" alt="image" src="https://user-images.githubusercontent.com/92745924/155081635-5a24db11-3e05-49a0-a1fc-c3bf84cc7ada.png">
- Use of the branches.
One should never commit at the main/master branch because it's used by open-source deveopers, and your code which is not been finalized might consists of some bugs so should go on separate branch so that users aren't affected.

- Creating new branch.
git branch branchName

- Head.
All the new features that you're adding will be added up to the branch where head (*) is pointed to.

<img width="960" alt="image" src="https://user-images.githubusercontent.com/92745924/155084448-5d5cd377-822d-432e-9a50-66bb9e478b75.png">
- You are not the only one who are contributing to the codebase, to direct some other developer to the main branch and not to your's then:
<img width="960" alt="image" src="https://user-images.githubusercontent.com/92745924/155085156-0bd8b420-7c5f-4bf9-80e1-35eab6a7a058.png">
- These changes are now finalized, people who are maintaining this project you'll tell them hey my code is finalized can you pls merge it to main code.
git merge branchname
<img width="960" alt="image" src="https://user-images.githubusercontent.com/92745924/155096562-0af7b78d-cafc-427c-a52b-b5f75f01f7b4.png">
git push origin master
<img width="960" alt="image" src="https://user-images.githubusercontent.com/92745924/155097681-28d3a2dd-eb90-4322-8c46-a1f404b0f138.png">
<img width="960" alt="image" src="https://user-images.githubusercontent.com/92745924/155097772-d4cee4af-1025-4896-992c-52833cdc1884.png">
- You want to work on an existing repository and it belongs to an organization to which you don't have an access, then 
i) fork that repo at your local drive
ii) copy the URL
iii) On the terminal write (git clone URL)
iv) ORIGIN URL : to your own account 
    UPSTREAM URL : from where you have forked that project-> git remote add upstream URL
    
## Pull Request
- STEPS->
<img width="960" alt="image" src="https://user-images.githubusercontent.com/92745924/155101869-faefc0c6-802e-42b5-ab4b-d5b28a42be7a.png">
<img width="960" alt="image" src="https://user-images.githubusercontent.com/92745924/155102059-8d1d5c0a-13c9-4fc1-b302-1422e5eb50a5.png">
<img width="960" alt="image" src="https://user-images.githubusercontent.com/92745924/155102522-458b7a0e-b391-4686-9dcf-146e3590b007.png">
(Checkout : Basically means head will move to the specified branch!)
<img width="960" alt="image" src="https://user-images.githubusercontent.com/92745924/155102857-2f77f3b4-b093-4730-b260-da40b1b4bdb3.png">
- Merge my branch to the main branch
(You can push to origin URL i.e. your's URL but not to the upstream URL)
(Whenever you are having some new feature create new branch as well as pull request)
Reason: Because a new branch can only be created if we have new pull request!!!

- Removing the commit from pull request by force
git reset previous one's ID->git add . -> git unstash -> git push origin branchName -f

- Merge conflict
Suppose khushboo made change in line 2 and I too made some change in line 2 then git will get confused to accept whose's change
it will ask for help.
