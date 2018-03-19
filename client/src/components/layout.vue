<template>
    <ph-window>
        <ph-toolbar type="header" title="ADMIN">
            <ph-toolbar-actions>
                <div class="btn-group">
                    <ph-button> <span class="icon icon-home"></span></ph-button>
                    <ph-button> <span class="icon icon-folder"></span> </ph-button>
                </div>
            </ph-toolbar-actions>
        </ph-toolbar>
        <ph-window-content>
            <ph-pane-group>
                <ph-pane size="sm" :sidebar="true">
                    <ph-nav-group title="Favorites">
                        <ph-nav-group-item :active="true">
                            <icon icon="home"></icon>Home</ph-nav-group-item>
                        <ph-nav-group-item>
                            <icon icon="download"></icon>Downloads</ph-nav-group-item>
                        <ph-nav-group-item>
                            <icon icon="folder"></icon>Documents</ph-nav-group-item>
                        <ph-nav-group-item>
                            <icon icon="signal"></icon>AirPlay</ph-nav-group-item>
                        <ph-nav-group-item>
                            <icon icon="print"></icon>Applications</ph-nav-group-item>
                        <ph-nav-group-item>
                            <icon icon="cloud"></icon>Desktop</ph-nav-group-item>
                    </ph-nav-group>
    
                </ph-pane>
                <ph-pane>
                    <ph-tab-group>
                        <ph-tab-item v-for=" tab in  tabs" :active="isActive( tab)" @cancel="cancel( tab)" @click.native="update( tab)">
                            ph-tab {{ tab.index }}
                        </ph-tab-item>
                        <ph-tab-item :fixed="true" icon="plus" @click.native="add"></ph-tab-item>
                    </ph-tab-group>
                    <table class="table-striped">
                        <thead>
                            <tr>
                                <th>Name</th>
                                <th>Kind</th>
                                <th>File Size</th>
                            </tr>
                        </thead>
                        <tbody>
                            <tr>
                                <td>photon.css</td>
                                <td>CSS</td>
                                <td>28K</td>
                            </tr>
                            <tr>
                                <td>photon.css</td>
                                <td>CSS</td>
                                <td>28K</td>
                            </tr>
                            <tr>
                                <td>photon.css</td>
                                <td>CSS</td>
                                <td>28K</td>
                            </tr>
    
                            <tr>
                                <td>photon.css</td>
                                <td>CSS</td>
                                <td>28K</td>
                            </tr>
                        </tbody>
                    </table>
                </ph-pane>
            </ph-pane-group>
        </ph-window-content>
        <ph-toolbar type="footer">
            <ph-toolbar-actions>
    
            </ph-toolbar-actions>
        </ph-toolbar>
    </ph-window>
</template>

<script>
    export default {
        data() {
            return {
                tabs: [{
                        index: 1,
                        title: 'Tab'
                    },
                    {
                        index: 2,
                        title: 'Tab'
                    },
                    {
                        index: 3,
                        title: 'Tab'
                    }
                ],
                active: 2
            }
        },
        computed: {
            title() {
                return `Header with tabs (active: ${this.active})`
            }
        },
        methods: {
            isActive(tab) {
                return tab.index === this.active
            },
            add() {
                // this.$log('added')
                const last = this.tabs[this.tabs.length - 1].index
                this.tabs.push({
                    index: last + 1,
                    title: 'Tab'
                })
            },
            update(tab) {
                // this.$log(`updated to ${tab.index}`)
                this.active = tab.index
            },
            cancel(tab) {
                // this.$log(`close tab ${tab.index}`)
                const index = this.tabs.findIndex(t => t === tab)
                this.tabs.splice(index, 1)
            }
        }
    }
</script>
