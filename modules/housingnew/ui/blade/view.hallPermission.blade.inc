<?php
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';

include_once MODULES_NEWHOUSING_BAO.'class.hallPermissionbao.inc';

$_HallPermissionBAO = new HallPermissionBAO();
$_DB = DBUtil::getInstance();
$_SESSION["Id"] = $_GET['id'];


$Result = new Result();

if(isset($_POST['Post'])){
	$HallPermission = new HallPermission();
	$HallPermission->setId(Util::getGUID());
	$HallPermission->setIdd($_DB->secureinput($_POST['idd']));
	$HallPermission->setHallId($_DB->secureinput($_SESSION["Id"]));


	$Result = $_HallPermissionBAO->HallPermission($HallPermission);

 	

}


if(isset($_GET['edit']))
{
	$HallPermission = new HallPermission();
	$HallPermission->setId($_GET['edit']);
	$getROW = $_HallPermissionBAO->readHallPermission($HallPermission)->getResultObject(); 
}




if(isset($_POST['update']))
{
	$HallPermission = new HallPermission();

    $HallPermission->setId ($_GET['edit']);
    //$HallPermission->setReceiver( $_POST['receiver'] );
    $HallPermission->setIdd( $_POST['idd'] );


    //$HallPermission->setHallId( $_SESSION["Id"] );

    $_HallPermissionBAO->updateHallPermission($HallPermission);
}



if(isset($_GET['dell']))
{

	$HallPermission = new HallPermission();
	$HallPermission->setId($_GET['dell']);
	$_HallPermissionBAO->deleteHallPermission($HallPermission); 

	
}