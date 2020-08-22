<?php
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';

include_once MODULES_ISSUE_BAO.'class.createIssuebao.inc';

$_CreateIssueBAO = new CreateIssueBAO();
$_DB = DBUtil::getInstance();

$Result = new Result();









//saving a new application
if(isset($_POST['Post'])){
	$CreateIssue = new CreateIssue();
	$CreateIssue->setId(Util::getGUID());
	$CreateIssue->setSubject($_DB->secureinput($_POST['subject']));
	
	//$HousingApplication->setReceiverDepartment($_DB->secureinput($_POST['txtReceiverDepartment']));
	
	$CreateIssue->setBody($_DB->secureinput($_POST['body']));
	$CreateIssue->setDate($_DB->secureinput(date("Y/m/d")));

 $uploadOk = 1;
    
    $target_dir = "./uploads/issues/";

    $target_file = $target_dir.basename($_FILES["fileToUpload"]["name"]);
    $ext = pathinfo($target_file, PATHINFO_EXTENSION);

    $target_file_link = random_string(10).".".$ext;
    //$id = hash_file('md5',$_FILES["fileToUpload"]["tmp_name"]);

    $target_file_link = $target_dir.$target_file_link;



 $link = $_FILES["fileToUpload"]["tmp_name"];

           
       
     $CreateIssue->setLinks($target_file_link);
           

if ($uploadOk == 0) {
        echo '<br>'.'<strong style=" color:red; ">'."Sorry, your file was not uploaded.".'</strong>';
// if everything is ok, try to upload file
    } else {
        if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file_link)) {
            echo '<br>'.'<strong style=" color:green; ">'."The file ". basename( $_FILES["fileToUpload"]["name"]). " has been uploaded.".'</strong>';
        }

        else
        {
        	echo "not done";
        }
    }






















	$Result = $_CreateIssueBAO->CreateIssue($CreateIssue);

 	

}




if(isset($_GET['edit']))
{
	$CreateIssue = new CreateIssue();
	$CreateIssue->setId($_GET['edit']);
	$getROW = $_CreateIssueBAO->readCreateIssue($CreateIssue)->getResultObject(); 
}

if(isset($_POST['update']))
{
	$CreateIssue = new CreateIssue();

    $CreateIssue->setId ($_GET['edit']);
    //$CreateIssue->setReceiver( $_POST['receiver'] );
    $CreateIssue->setSubject( $_POST['subject'] );


    $CreateIssue->setBody( $_POST['body'] );

    $uploadOk = 1;
    
    $target_dir = "./uploads/issues/";
if($_FILES["fileToUpload"]["name"] != null)
{
    $getROW = $_CreateIssueBAO->readCreateIssue($CreateIssue)->getResultObject();
    if(unlink($getROW->getLinks()))
        {
            echo"well done";
        }

    $target_file = $target_dir.basename($_FILES["fileToUpload"]["name"]);
    $ext = pathinfo($target_file, PATHINFO_EXTENSION);

    $target_file_link = random_string(10).".".$ext;
    //$id = hash_file('md5',$_FILES["fileToUpload"]["tmp_name"]);

    $target_file_link = $target_dir.$target_file_link;



 $link = $_FILES["fileToUpload"]["tmp_name"];

           
       
     $CreateIssue->setLinks($target_file_link);
           

if ($uploadOk == 0) {
        echo '<br>'.'<strong style=" color:red; ">'."Sorry, your file was not uploaded.".'</strong>';
// if everything is ok, try to upload file
    } else {
        if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file_link)) {
            echo '<br>'.'<strong style=" color:green; ">'."The file ". basename( $_FILES["fileToUpload"]["name"]). " has been uploaded.".'</strong>';
        }

        else
        {
            echo "not done";
        }
    }

}
else
{
    $getROW = $_CreateIssueBAO->readCreateIssue($CreateIssue)->getResultObject(); 
    $CreateIssue->setLinks($getROW->getLinks());
}
   

    $_CreateIssueBAO->updateCreateIssue($CreateIssue);

    
	header("Location:".PageUtil::$CREATE_ISSUE);
}

if(isset($_GET['del']))
{

	$CreateIssue = new CreateIssue();
	$CreateIssue->setId($_GET['del']);
	$_CreateIssueBAO->deleteCreateIssue($CreateIssue); 

	header("Location:".PageUtil::$CREATE_ISSUE);
}

function random_string($length) {
    $key = '';
    $keys = array_merge(range(0, 9), range('a', 'z'));

    for ($i = 0; $i < $length; $i++) {
        $key .= $keys[array_rand($keys)];
    }

    return $key;

}
?>

