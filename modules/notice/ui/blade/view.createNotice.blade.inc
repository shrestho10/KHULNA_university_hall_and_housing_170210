<?php
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';

include_once MODULES_NOTICE_BAO.'class.createNoticebao.inc';

$_CreateNoticeBAO = new CreateNoticeBAO();
$_DB = DBUtil::getInstance();

$Result = new Result();









//saving a new application
if(isset($_POST['Post'])){
	$CreateNotice = new CreateNotice();
	$CreateNotice->setId(Util::getGUID());
	$CreateNotice->setSubject($_DB->secureinput($_POST['subject']));
	
	//$HousingApplication->setReceiverDepartment($_DB->secureinput($_POST['txtReceiverDepartment']));
	
	$CreateNotice->setBody($_DB->secureinput($_POST['body']));
	$CreateNotice->setDate($_DB->secureinput(date("Y/m/d")));

 $uploadOk = 1;
    
    $target_dir = "./uploads/notice/";

    $target_file = $target_dir.basename($_FILES["fileToUpload"]["name"]);
    $ext = pathinfo($target_file, PATHINFO_EXTENSION);

    $target_file_link = random_string(10).".".$ext;
    //$id = hash_file('md5',$_FILES["fileToUpload"]["tmp_name"]);

    $target_file_link = $target_dir.$target_file_link;



 $link = $_FILES["fileToUpload"]["tmp_name"];

           
       
     $CreateNotice->setLinks($target_file_link);
           

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






















	$Result = $_CreateNoticeBAO->createNotice($CreateNotice);

 	

}




if(isset($_GET['edit']))
{
	$CreateNotice = new CreateNotice();
	$CreateNotice->setId($_GET['edit']);
	$getROW = $_CreateNoticeBAO->readCreateNotice($CreateNotice)->getResultObject(); 
}

if(isset($_POST['update']))
{
	$CreateNotice = new CreateNotice();

    $CreateNotice->setId ($_GET['edit']);
    //$CreateNotice->setReceiver( $_POST['receiver'] );
    $CreateNotice->setSubject( $_POST['subject'] );


    $CreateNotice->setBody( $_POST['body'] );

    $uploadOk = 1;
    
    $target_dir = "./uploads/notice/";
if($_FILES["fileToUpload"]["name"] != null)
{
    $getROW = $_CreateNoticeBAO->readCreateNotice($CreateNotice)->getResultObject();
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

           
       
     $CreateNotice->setLinks($target_file_link);
           

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
    $getROW = $_CreateNoticeBAO->readCreateNotice($CreateNotice)->getResultObject(); 
    $CreateNotice->setLinks($getROW->getLinks());
}
   

	$_CreateNoticeBAO->updateCreateNotice($CreateNotice);

	header("Location:".PageUtil::$CREATE_NOTICE);
}

if(isset($_GET['del']))
{

	$CreateNotice = new CreateNotice();
	$CreateNotice->setId($_GET['del']);
	$_CreateNoticeBAO->deleteCreateNotice($CreateNotice); 

	header("Location:".PageUtil::$CREATE_NOTICE);
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

