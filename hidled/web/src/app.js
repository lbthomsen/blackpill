/* 
 * Main app
 */
/* global angular */

(function () {

    const appName = "hidled";
    const app = angular.module(appName, []);

    app.run(["$log", "$window",
        async function ($log, $window) {
            $log.debug(appName + " starting");
            $log.debug("Env: %o", $window);

            $window.navigator.hid.getDevices().then(function(devices) {
                $log.debug("Got devices: %o", devices);
            });


        }
    ]);

})();
/*
 * vim: ts=4 et nowrap autoindent
 */