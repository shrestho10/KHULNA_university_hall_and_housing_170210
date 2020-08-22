<?php



include_once MODULES_NOTICE_BLADE.'view.viewNotice.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';

$_SESSION["id"] = $_GET['id'];
echo "jgjgjhg";
?>
<div class="panel-body">
        <form method="post">

 <?php

echo $_SESSION["id"];

                    $Result = $_ViewNoticeBAO->getNoticeById($_SESSION["id"]);
                    if ($Result->getIsSuccess()) {
                        $Notice1 = $Result->getResultObject();
                        

                            
                          header('Content-Type:'."image/jpg");
                            
                          echo $Notice1->getMyFile();


                         
                   
                     
                     }
                 
                 ?>

</form>
</div>
                        