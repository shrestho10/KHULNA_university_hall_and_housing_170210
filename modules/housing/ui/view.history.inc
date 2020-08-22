

<?php


include_once MODULES_HOUSING_BLADE.'view.housingRoomAssign.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';

include_once MODULES_HOUSING_BLADE.'view.housingRoom.blade.inc';

$_SESSION["id"] = $_GET['id'];


?>

<div class="panel-body">
        <form method="post">
            <table class="table table-bordered">

            <?php
            
            
            
            $Result = $_HousingRoomAssignBAO->getHistoryFromId($_SESSION["id"]);
            
            if($Result->getIsSuccess()){

                $HistoryL = $Result->getResultObject();

            ?> 
                <tr>
                    <th>Room No</th>
                    <th>FirstDate</th>
                    <th>LastDate</th>
                    

    
                </tr>
                <?php

                for($i = 0; $i < sizeof ($HistoryL) ; $i++) {
                     $History = $HistoryL[$i];
                    ?>
                    <tr>
                    <td><?php $id = $History->getRoomId();
                    //echo $id;
                            $Result2 = $_HousingRoomAssignBAO->getRoomNoFromId($id);
                            if ($Result2->getIsSuccess()) {

                                $Housing = $Result2->getResultObject();

                                echo $Housing->getRoomNo();
                            }
                            
                            ?>
                                
                        </td>

                    <td><?php echo $History->getAppDate(); ?></td>
                    <td><?php echo $History->getLeaveDate(); ?></td>
                </tr>
                <?php 
            }
        }
            ?>
</table>
</form>
</div>


