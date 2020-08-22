<?php

include_once MODULES_NOTICE_BLADE.'view.viewNotice.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';

?>



<div class="panel col-md-8 col-md-offset-2" style="border-top: outset; border-left: outset;
                                border-bottom: inset; border-right: inset; margin-top: 50px;">
    <div class="panel-heading" align="center">
        <h4><u>View Notice</u></h4>
    </div>
    <div class="panel-body">
            <table class="table table-bordered">
                <tr>
                    
                    
                    <th>Subject</th>
                    <th>Submission Date</th>
                    <th>Notice</th>
                    <th>Attachment</th>
                </tr>
               
                    <?php


                    $Result = $_ViewNoticeBAO->getAllNotice();
                    if ($Result->getIsSuccess()) {
                        $NoticeList = $Result->getResultObject();
                        for ($i=0; $i < sizeof($NoticeList); $i++) { 
                            $Notice = $NoticeList[$i];

                            ?>
                            <tr>
                            
                         <td><?php echo $Notice->getSubject();?></td>
                            <td><?php echo $Notice->getDate();?></td>
                            <td><a href="notice_show.php?view=<?php echo $Notice->getId();?>" onclick="return ; ">Notice</a></td>

                             <td><a class="btn btn-primary" href="<?php echo "".$Notice->getLinks(); ?>" role="button">Attachment</a>
                         </td>
                            </tr>
                            <?php
                        }
                    }

                    ?>
                
                    
                </table>
            
    </div>
</div>



