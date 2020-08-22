<?php

include_once MODULES_NOTICE_BLADE.'view.CreateNotice.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';

$_SESSION["aid"] = $_GET['view'];


?>


<script type="text/javascript">
function Confirm(form){
alert("Notice submit successfully!"); 
form.submit();
}
</script>

<div class="panel col-md-10 col-md-offset-1" style="font-size: 16px; border-top: outset; border-left: outset;
                                border-bottom: inset; border-right: inset; margin-top: 50px">
    <div class="panel-heading" align="center">
        <h3><u>Notice</u></h3>
    </div>
    <div id='message'></div>
    <div class="panel-body">
        
            <form class="form-horizontal" method="post" name="form">
            <?php
 
                $Result = $_CreateNoticeBAO->getNoticeBody($_SESSION["aid"]);

                if($Result->getIsSuccess()){

                    $CreateNotice = $Result->getResultObject();
                       
                ?>
                
              
                    
                <textarea class="form-control" name="body" style="width:100%; height: 500px; font-size: 16px" disabled><?php echo $CreateNotice->getBody(); ?></textarea>
                   
              
                
            
               <?php }?> 
               <br>
               <br>
                             
            </form>
           
    </div>
</div>
 


