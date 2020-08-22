<?php


include_once UTILITY.'class.util.inc';
include_once MODULES_USER.'bao/class.userbao.inc';
include_once MODULES_USER.'bao/class.rolebao.inc';

$_UserBAO = new UserBAO();
$_RoleBAO = new RoleBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


/* saving a new user account*/
if(isset($_POST['request']))
{
	 $User = new User();	

	 $User->setID(strtolower($_DB->secureInput($_POST['txtEmail']))); 
	 
	 $User->setUniversityID($_DB->secureInput($_POST['txtUniversityID']));
     $User->setFirstName($_DB->secureInput($_POST['txtFirstName']));
     $User->setLastName($_DB->secureInput($_POST['txtLastName']));
	 
	 $User->setEmail(strtolower($_DB->secureInput($_POST['txtEmail']))); 

     $User->setPassword($_DB->secureInput($_POST['txtPassword']));

     $User->setStatus('pending');

    
    if(isset($_POST['selectRole'])){ 
		$Role = new Role();
		$Role->setID($_POST['selectRole']);
		$Roles[]=$Role;		
		$User->setRoles($Roles);
	}
	
	$Result = $_UserBAO->newUserRequest($User);		

	if($Result->getIsSuccess())
		echo '<strong>'.$Result->getResultObject().'</strong>';	


}


//echo '<br> log:: exit blade.user_new.inc';
//$_Log->log(LogUtil::$DEBUG,"exit blade.user_new.inc");

?>