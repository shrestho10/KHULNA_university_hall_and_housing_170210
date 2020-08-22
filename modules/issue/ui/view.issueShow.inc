<?php

include_once MODULES_ISSUE_BLADE.'view.createIssue.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';

$_SESSION["aid"] = $_GET['view'];


?>


<script type="text/javascript">
function Confirm(form){
alert("Issue submit successfully!"); 
form.submit();
}
</script>

<div class="panel col-md-10 col-md-offset-1" style="font-size: 16px; border-top: outset; border-left: outset;
                                border-bottom: inset; border-right: inset; margin-top: 50px">
    <div class="panel-heading" align="center">
        <h3><u>Issue</u></h3>
    </div>
    <div id='message'></div>
    <div class="panel-body">
        
            <form class="form-horizontal" method="post" name="form">
            <?php
 
                $Result = $_CreateIssueBAO->getIssueBody($_SESSION["aid"]);

                if($Result->getIsSuccess()){

                    $CreateIssue = $Result->getResultObject();
                       
                ?>
                
              
                    
                <textarea class="form-control" name="body" style="width:100%; height: 500px; font-size: 16px" disabled><?php echo $CreateIssue->getBody(); ?></textarea>
                   
              
                
            
               <?php }?> 
               <br>
               <br>
                             
            </form>
           
    </div>
</div>
 


